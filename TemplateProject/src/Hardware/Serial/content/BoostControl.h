#ifndef BOOSTCONTROL_H
#define BOOSTCONTROL_H

#include <QObject>
#include "SerialBase.h"

class BoostControl:public SerialBase
{
public:
    explicit BoostControl();
    void InitDevice();

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

};

#endif // BOOSTCONTROL_H
