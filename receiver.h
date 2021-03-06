#pragma once
#include <QUdpSocket>
#include <QHostAddress>
#include "packageFormat.pb.h"

class Receiver : public QUdpSocket
{
    Q_OBJECT
public:
    Receiver(int,int,const QHostAddress&, const QString&, QObject *parent = 0);
private slots:
    void processPendingDatagrams();
    void initRec();
    void reportPackage(UdpStream::UdpBytes::PackStatus);
private:
    QString dFolder, filePath;
    QHostAddress groupAddress;
    int filePort, responsePort;
    int recentDatagrammID=-1;
    QByteArray totalBytes;
signals:
    void gotPackage(UdpStream::UdpBytes::PackStatus);
};
