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
private:
    int id;
    QHostAddress groupAddress;
    QUdpSocket socket2;
signals:
    void printRec(const QString&);
};
