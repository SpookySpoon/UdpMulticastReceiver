#include <QtNetwork>
#include <QDebug>
#include "pbuff.h"
#include "receiver.h"

Receiver::Receiver(int someFilePort, int someResPort, const QHostAddress& someGroupAddress, const QString& someSavePath, QObject *parent)
    : QUdpSocket(parent),filePort(someFilePort), responsePort(someResPort),groupAddress(someGroupAddress), dFolder(someSavePath)
{
    initRec();
    connect(this, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
    connect(this, SIGNAL(gotPackage(UdpStream::UdpBytes::PackStatus)),this, SLOT(reportPackage(UdpStream::UdpBytes::PackStatus)));
}

void Receiver::initRec()
{
    this->bind(QHostAddress::AnyIPv4, filePort, QUdpSocket::ShareAddress);
    this->joinMulticastGroup(groupAddress);
}


void Receiver::processPendingDatagrams()
{
    QByteArray fileBytes;
    while (this->hasPendingDatagrams())
    {
        fileBytes.resize(this->pendingDatagramSize());
        this->readDatagram(fileBytes.data(), fileBytes.size());
    }
    UdpStream::UdpBytes tempPackage=ProtoBytes<UdpStream::UdpBytes>::protoFromByteArray(fileBytes);
    if(tempPackage.packstatus()==UdpStream::UdpBytes::PackStatus::UdpBytes_PackStatus_FIRST)
    {
        totalBytes="";
        filePath=QString("%1\\%2").arg(dFolder)
                .arg(QString::fromStdString(tempPackage.packcontent()));
        recentDatagrammID=0;
        emit gotPackage(tempPackage.packstatus());
    }

    if(recentDatagrammID-tempPackage.packid()==-1)
    {
        recentDatagrammID=tempPackage.packid();
        totalBytes.append(tempPackage.packcontent().data(),tempPackage.packcontent().size());
        emit gotPackage(tempPackage.packstatus());
        qDebug()<<"bytes received: "<<fileBytes.size();
        if(tempPackage.packstatus()==UdpStream::UdpBytes::PackStatus::UdpBytes_PackStatus_LAST)
        {
            QFile myFile(filePath);
            myFile.open(QIODevice::ReadWrite);
            myFile.write(totalBytes);
            myFile.close();
            qDebug()<<"Transfer finished. Filename: "<<filePath;
        }
    }
}

void Receiver::reportPackage(UdpStream::UdpBytes::PackStatus mes)
{
    UdpStream::UdpBytes responce;
    responce.set_packstatus(mes);
    QByteArray opa = ProtoBytes<UdpStream::UdpBytes>::protoToByteArray(responce);
    int rep=this->writeDatagram(opa.data(), opa.size(),
                                 groupAddress, responsePort);
    qDebug()<<"reported bytes: "<<rep;
}


