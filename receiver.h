#pragma once
#include <QUdpSocket>
#include <QHostAddress>


class Receiver : public QUdpSocket
{
    Q_OBJECT

public:
    Receiver(QObject *parent = 0);
private slots:
    void processPendingDatagrams();
    void initRec();
    void reportPackage(const QString&);
private:
    int id=0;
    QHostAddress groupAddress;
    QByteArray totalBytes;
    QUdpSocket socket2;
signals:
    void printRec(const QString&);
    void gotPackage(const QString&);
};
