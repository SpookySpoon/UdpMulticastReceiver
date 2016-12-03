#include <QDebug>
#include "receiverhub.h"


ReceiverHub::ReceiverHub(QObject* parent):
    QObject(parent),recOne(),tOne()
{
    connect(&tOne, SIGNAL(started()),&recOne, SLOT(initRec()));
    connect(&recOne, SIGNAL(readyRead()),&recOne, SLOT(processPendingDatagrams()));
    connect(&recOne, SIGNAL(printRec(QString)),this, SLOT(typeData(QString)));
    recOne.moveToThread(&tOne);
    tOne.start();
}


void ReceiverHub::typeData(const QString& message)
{
    qDebug()<<message;
}
