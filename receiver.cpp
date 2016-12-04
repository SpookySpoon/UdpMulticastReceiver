#include <QtNetwork>
#include <QDebug>
#include "pbuff.h"
#include "receiver.h"
#include "packageFormat.pb.h"

Receiver::Receiver(QObject *parent)
    : QUdpSocket(parent),  socket2()
{
    initRec();
    connect(this, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
    connect(this, SIGNAL(gotPackage(QString)),this, SLOT(reportPackage(QString)));
}

void Receiver::initRec()
{
    groupAddress = QHostAddress("239.255.43.21");
    this->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    this->joinMulticastGroup(groupAddress);
}


void Receiver::processPendingDatagrams()
{
    qDebug()<<"receiving data";
    QByteArray fileBytes;
    fileBytes.resize(this->pendingDatagramSize());
    this->readDatagram(fileBytes.data(), fileBytes.size());
    udpStream::updBytes tempPackage=ProtoBytes::protoFromByteArray(datagram);

    totalBytes.append(fileBytes);
    if(fileBytes.contains("{konetsN@hy%}"))
    {
        QFile myFile("C:/Users/Home/Desktop/someTrack.mp3");
        myFile.open(QIODevice::ReadWrite);
        myFile.write(totalBytes);
        myFile.close();
        qDebug()<<"Transfr finished";
        emit gotPackage("Stop");
    }
    else
    {
        qDebug()<<"bytes received: "<<fileBytes.count();
        emit gotPackage("We got the stuff!");
    }
}

void Receiver::reportPackage(const QString& mes)
{
    QByteArray opa = mes.toLatin1();
    int rep=this->writeDatagram(opa.data(), opa.size(),
                                 groupAddress, 45455);
    qDebug()<<"reported bytes: "<<rep;
}

