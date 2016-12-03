#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "receiver.h"

Receiver::Receiver(QObject *parent)
    : QUdpSocket(parent)
{

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
    this->joinMulticastGroup(groupAddress);
}


void Receiver::processPendingDatagrams()
{
    static int opa=0;
    ++opa;
    while (this->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(this->pendingDatagramSize());
        this->readDatagram(datagram.data(), datagram.size());
        QString emitM=datagram.data();
        QString emitMes=QString("%1%2 shows %3").arg("Receiver №").arg(id).arg(QString::fromStdString(emitM.toStdString()));
        emit printRec(emitMes);
//        qDebug()<<datagram.data();
    }
}
