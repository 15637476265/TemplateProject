#ifndef SERIALH_H
#define SERIALH_H


#include <QMutex>
#include <QThread>
#include <QObject>
#include "content/BoostControl.h"
#include "content/QSerialControl.h"
#include "content/ModbusControl.h"

#include <memory>

namespace Serial {
    typedef enum Control_Tag{
        BOOST_MODE =(0u),
        QT_MODE ,
        MODBUS,
        TAG_ALL
    }REQUEST_MODE;
}



static Serial::REQUEST_MODE current_mode = Serial::QT_MODE;


class SerialManager{

    SerialManager(){
        init();
    }



public:

    ///
    QStringList ScanSerial(){
        return mySerial.get()->ScanSerial();
    }

    ///
    void OpenPort(QString config){
        mySerial.get()->OpenPort(config);
    }

    ///
    QByteArray SendUntilRec(const QByteArray &sendBuf,int msecs = 3000){
        return mySerial.get()->SendUntilRec(sendBuf,msecs);
    }

    ///
    void SendBuff(const QByteArray &sendBuf){
        mySerial.get()->SendBuff(sendBuf);
    }

    ///
    void CloseSerial(){
        mySerial.get()->CloseSerial();
    }

    ///
    bool GetOpened(){
        return mySerial.get()->GetOpened();
    }





    static SerialManager* GetInstance(){
        static QMutex mutex;
        static QScopedPointer<SerialManager> inst;
        if (Q_UNLIKELY(!inst)) {
            mutex.lock();
            if (!inst) {
                inst.reset(new SerialManager);
            }
            mutex.unlock();
        }
        return inst.data();
    }




private:
    static std::shared_ptr<SerialBase> mySerial ;

    std::shared_ptr<SerialBase> operator->() {
        return mySerial;
    }


private:
    void init(){

        switch (current_mode) {
        case Serial::BOOST_MODE:
            mySerial.reset(new BoostControl);
            break;
        case Serial::QT_MODE:
            mySerial.reset(new QSerialControl);
            break;
        case Serial::MODBUS:
            mySerial.reset(new ModbusControl);
            break;
        default:
            mySerial.reset(new SerialBase);
            break;
        }
    }

};


#endif // SERIALH_H
