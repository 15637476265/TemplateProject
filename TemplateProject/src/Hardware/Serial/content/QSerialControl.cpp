#include "QSerialControl.h"
#include <QDir>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>


QSerialControl::QSerialControl()
{
    isServiceRunning = false;
}

QSerialControl::~QSerialControl()
{
    if(!isServiceRunning) return;

    if (m_serialPort->isOpen()) {
        m_serialPort->close();
        m_serialPort->disconnect();
    }

    m_thread->disconnect();
    delete m_serialPort;

    m_thread->deleteLater();
}


void QSerialControl::creatService()
{
    if(isServiceRunning) return;
    m_serialPort = new QSerialPort();//实例化串口类一个对象
    m_thread = new QThread();
    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()),Qt::QueuedConnection);
    connect(m_thread,&QThread::finished,m_thread,&QObject::deleteLater);
    this->moveToThread(m_thread);
    m_serialPort->moveToThread(m_thread);
    startService();
}


void QSerialControl::startService()
{
    if(!m_thread->isRunning()){
        m_thread->start(QThread::TimeCriticalPriority);  //启动线程
        isServiceRunning = true;
    }

}



QStringList QSerialControl::ScanSerial()
{
    QStringList ttyList ;
    foreach (const QSerialPortInfo &Info, QSerialPortInfo::availablePorts()) {
        ttyList.append(Info.portName());
    }
    return ttyList;
}



void QSerialControl::OpenPort(QString port,QString bau)
{
    creatService();
    if(m_serialPort->isOpen()){
        m_serialPort->clear();
        m_serialPort->close();
    }
    m_serialPort->setPortName(port);

    if(!m_serialPort->open(QIODevice::ReadWrite)){
        qDebug()<<port<<"打开失败!";
        return;
    }

    if(bau.compare("9600")||bau.compare("115200")||bau.compare("1200")){
        qint32 rate = static_cast<qint32>(bau.toLong());
        m_serialPort->setBaudRate(rate,QSerialPort::AllDirections);
        m_serialPort->setDataBits(QSerialPort::Data8);		//数据位为8位
        m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
        m_serialPort->setParity(QSerialPort::NoParity);	//无校验位
        m_serialPort->setStopBits(QSerialPort::OneStop); //一位停止位
    }else {
        qCritical("Error Baud Rate!");
    }
    startService();
}


void QSerialControl::CloseSerial()
{
    m_serialPort->clear();
    m_serialPort->close();
}


void QSerialControl::receiveInfo()
{
    /* 如果本次数据帧接受错误，那么先不接受 */
    if(m_serialPort->bytesAvailable() >= MainSerialPortOneFrameSize)
    {
        QByteArray info = m_serialPort->readAll();
        if(!info.isEmpty())
        {
            buff = info;
        }
    }

}


QByteArray QSerialControl::SendUntilRec(const QByteArray &sendBuf,int msecs)
{
    buff.clear();
    qint64 sendCount;
    sendCount = m_serialPort->write(sendBuf);

    qDebug()<<__FUNCTION__<<"Write to serial: "<<sendBuf.toHex()<<sendCount;
    m_serialPort->waitForBytesWritten(msecs);
    m_serialPort->waitForReadyRead(msecs);
    return buff;
}

bool QSerialControl::GetOpened()
{
    return m_serialPort->isOpen();
}


void QSerialControl::processJson(QByteArray byteArray)
{
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (doucment.isObject()) { // JSON 文档为对象
            QJsonObject object = doucment.object();  // 转化为对象
            if (object.contains("port")) {  // 包含指定的 key
                QJsonValue value = object.value("port");
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    port = strName;
                }
            }
            if (object.contains("bau")) {
                QJsonValue value = object.value("bau");
                if (value.isDouble()) {
                    int nFrom = value.toVariant().toInt();
                    bau =  nFrom;
                }
            }

        }
    }else {
        qDebug()<<"Error Read Json";
    }
}

void QSerialControl::OpenPort(QString config)
{
    QFile file(config);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return;

    while (!file.atEnd()) {
      QByteArray byteArray = file.readLine();
      processJson(byteArray);
    }

}


//
void QSerialControl::SendBuff(const QByteArray &sendBuf){

    qint64 sendCount;
    buff.clear();
    sendCount = m_serialPort->write(sendBuf);


    qDebug()<<__FUNCTION__<<"Write to serial: "<<sendBuf.toHex()<<sendCount;
    m_serialPort->waitForBytesWritten(TIME_OUT_MS);
    m_serialPort->waitForReadyRead(TIME_OUT_MS);
}


