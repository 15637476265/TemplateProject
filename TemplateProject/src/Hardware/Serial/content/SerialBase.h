#ifndef SERIALBASE_H
#define SERIALBASE_H

#include <QString>
#include <iostream>
#include <QDebug>

class SerialBase
{
public:
    SerialBase();

    virtual QStringList ScanSerial();
    ///
    virtual QByteArray SendUntilRec(const QByteArray &sendBuf,int msecs = 3000);
    ///
    virtual bool GetOpened();
    ///
    virtual void OpenPort(QString config);

    ///
    virtual void CloseSerial();

    ///
    virtual void SendBuff(const QByteArray &sendBuf);
};

#endif // SERIALBASE_H
