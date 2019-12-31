#ifndef QSERIALCONTROL_H
#define QSERIALCONTROL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QMutex>
#include <QThread>
#include "SerialBase.h"

#define TIME_OUT_MS 3000
#define MainSerialPortOneFrameSize 4

class QSerialControl: public QObject, public SerialBase
{
    Q_OBJECT
public:
    explicit QSerialControl();
    ~QSerialControl();
    virtual QStringList ScanSerial() override;
    ///
    virtual QByteArray SendUntilRec(const QByteArray &sendBuf,int msecs = 3000) override;
    ///
    virtual bool GetOpened() override;
    ///
    virtual void OpenPort(QString config) override;

    ///
    virtual void CloseSerial() override;

    ///
    virtual void SendBuff(const QByteArray &sendBuf) override;


private:
    void startService();
    void creatService();
    QSerialPort *m_serialPort;
    QThread     *m_thread;

    QByteArray buff;
    QString port;
    int bau;
    bool isServiceRunning;

    void OpenPort(QString port,QString bau);//Open
    void processJson(QByteArray);



protected slots:
    void receiveInfo();
};

#endif // QSERIALCONTROL_H
