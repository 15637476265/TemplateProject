#ifndef RWFILE_H
#define RWFILE_H

#include <QObject>
#include <QFile>


class RWFile : public QObject
{
    Q_OBJECT
public:
    explicit RWFile(QObject *parent = nullptr);

    static  QByteArray ReadFile(QString path);
    static  std::string ReadFile(std::string path);
signals:

public slots:
};

#endif // RWFILE_H
