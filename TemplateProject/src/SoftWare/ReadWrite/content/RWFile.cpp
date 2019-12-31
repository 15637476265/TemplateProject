#include "RWFile.h"

RWFile::RWFile(QObject *parent) : QObject(parent)
{

}

QByteArray RWFile::ReadFile(QString path)
{
    QByteArray byteArray;
    try{
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) throw "file error";
        while (!file.atEnd()) {
          byteArray = file.readLine();
        }
    }catch(...){
        qWarning("File Open Failed:",path);
    }
    return byteArray;
}

std::string RWFile::ReadFile(std::string path)
{

}
