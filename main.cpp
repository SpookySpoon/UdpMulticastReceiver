#include <QCoreApplication>
#include <QIODevice>
#include <QFile>
#include <QList>
#include <QDebug>
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Receiver rec1(45454,45455,QHostAddress("239.255.43.21"),"C:\\Users\\Home\\Desktop\\Result");
    return app.exec();
}
