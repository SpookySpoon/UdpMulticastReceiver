#pragma once
#include <QUdpSocket>
#include <QHostAddress>


class Receiver : public QUdpSocket
{
    Q_OBJECT

public:
    Receiver(QObject *parent = 0);
    void setServerAddress(const QString&);
    void setDFolder(const QString&);
public slots:
    void requestAccess();
private slots:
    void processPendingDatagrams();
    void initRec();
    void reportPackage(const QString&);
    void selectServer(const QString&);
private:
    int id=0;
    QString dFolder;
    QHostAddress groupAddress;
    quint32 serverPort;
    QByteArray totalBytes;
signals:
    void printRec(const QString&);
    void gotPackage(const QString&);
};
