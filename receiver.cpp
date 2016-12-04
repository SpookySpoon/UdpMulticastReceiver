#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "receiver.h"

Receiver::Receiver(QObject *parent)
    : QUdpSocket(parent),  socket2()
{
    initRec();
    connect(this, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
    connect(this, SIGNAL(gotPackage(QString)),this, SLOT(reportPackage(QString)));
//    statusLabel = new QLabel(tr("Listening for multicasted messages"));
//    quitButton = new QPushButton(tr("&Quit"));
//    listOneButton = new QPushButton(tr("&List1"));
//    listTwoButton = new QPushButton(tr("&List2"));


//    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
//    connect(listOneButton, SIGNAL(clicked()), this, SLOT(listOne());
//    connect(listTwoButton, SIGNAL(clicked()), this, SLOT(listTwo()));

//    QHBoxLayout *buttonLayout = new QHBoxLayout;
//    buttonLayout->addStretch(1);
//    buttonLayout->addWidget(quitButton);
//    buttonLayout->addWidget(listOneButton);
//    buttonLayout->addWidget(listTwoButton);
//    buttonLayout->addStretch(1);

//    QVBoxLayout *mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(statusLabel);
//    mainLayout->addLayout(buttonLayout);
//    setLayout(mainLayout);

//    setWindowTitle(tr("Multicast Receiver"));
}

void Receiver::initRec()
{
    groupAddress = QHostAddress("239.255.43.21");
    this->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    this->joinMulticastGroup(groupAddress);
}


void Receiver::processPendingDatagrams()
{
//  this->SocketState::BoundState;
    qDebug()<<"receiving data";
    QByteArray fileBytes;
    while (this->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(this->pendingDatagramSize());
        this->readDatagram(datagram.data(), datagram.size());
        fileBytes.append(datagram);
//      QString emitM=datagram.data();
//      QString emitMes=QString("Receiver №1 shows %1").arg(QString::fromStdString(emitM.toStdString()));
////    emit printRec(emitMes);
//      qDebug()<<emitMes;
    }
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
    //    QFile myFile("C:/Users/Home/Desktop/someTrack.mp3");
//    myFile.open(QIODevice::ReadWrite);

//    myFile.write(fileBytes);
//    myFile.close();

}

void Receiver::reportPackage(const QString& mes)
{
    QByteArray opa = mes.toLatin1();
    int rep=this->writeDatagram(opa.data(), opa.size(),
                                 groupAddress, 45455);
    qDebug()<<"reported bytes: "<<rep;
}

