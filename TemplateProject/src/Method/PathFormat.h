#ifndef PATHFORMAT_H
#define PATHFORMAT_H

#include <QObject>
#include <QSysInfo>
#include <QDebug>


class PathFormat : public QObject
{
    Q_OBJECT
public:
    explicit PathFormat(QObject *parent = nullptr);
    void getCurrentOS();

    QString getCurretPath();

signals:

public slots:
private:

};

#endif // PATHFORMAT_H
