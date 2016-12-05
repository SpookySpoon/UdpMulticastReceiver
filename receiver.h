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
    QString dFolder="C:\Users\Home\Desktop\Result";
    QHostAddress groupAddress;
    int filePort, responsePort;
    QByteArray totalBytes;
signals:
    void printRec(const QString&);
    void gotPackage(const QString&);
};
