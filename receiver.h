#pragma once
#include <QUdpSocket>
#include <QHostAddress>


class Receiver : public QUdpSocket
{
    Q_OBJECT

public:
    Receiver(int,int,const QHostAddress&, const QString&, QObject *parent = 0);
private slots:
    void processPendingDatagrams();
    void initRec();
    void reportPackage(const QString&);
private:
    QString dFolder, filePath;
    QHostAddress groupAddress;
    int filePort, responsePort, recentDatagrammID=-1;
    QByteArray totalBytes;
signals:
    void gotPackage(const QString&);
};
