#include "PathFormat.h"

PathFormat::PathFormat(QObject *parent) : QObject(parent)
{
    getCurrentOS();
}

void PathFormat::getCurrentOS()
{
    qDebug()<<"Kernel type:"<<QSysInfo::kernelType();
    qDebug()<<"Kernel Version:"<<QSysInfo::kernelVersion();
    qDebug()<<"Release Version:"<<QSysInfo::productVersion();
    qDebug()<<"OS Type:"<<QSysInfo::prettyProductName();
}

QString PathFormat::getCurretPath()
{

}

