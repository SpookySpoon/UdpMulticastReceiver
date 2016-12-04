#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "receiver.h"

Receiver::Receiver(QObject *parent)
    : QUdpSocket(parent),  socket2()
{
    initRec();
    connect(this, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
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
    static int opa=1;
    id=opa++;
    groupAddress = QHostAddress("239.255.43.21");
    this->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    socket2.bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    this->joinMulticastGroup(groupAddress);
    socket2.joinMulticastGroup(groupAddress);
}


void Receiver::processPendingDatagrams()
{
    static int opa=0;
    ++opa;
//    this->SocketState::BoundState;
    while (this->hasPendingDatagrams()||socket2.hasPendingDatagrams()) {
        QByteArray datagram;
        QByteArray datagram1;
        datagram.resize(this->pendingDatagramSize());
        datagram1.resize(socket2.pendingDatagramSize());
        this->readDatagram(datagram.data(), datagram.size());
        socket2.readDatagram(datagram.data(), datagram.size());
        QString emitM=datagram.data();
        QString emitM1=datagram1.data();
        QString emitMes=QString("Receiver №1 shows %1").arg(QString::fromStdString(emitM.toStdString()));
        QString emitMes1=QString("Receiver №2 shows %1").arg(QString::fromStdString(emitM1.toStdString()));
//        emit printRec(emitMes);
        qDebug()<<emitMes<<"\n"<<emitMes1;
    }
}
