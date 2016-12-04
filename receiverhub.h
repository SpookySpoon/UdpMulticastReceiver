#pragma once
#include <QThread>
#include "receiver.h"

class ReceiverHub: public QObject
{
    Q_OBJECT
public:
    ReceiverHub(QObject* parent=nullptr);
    QThread tOne;
    Receiver recOne;
public slots:
    void typeData(const QString&);


};

