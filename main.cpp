#include <QApplication>
#include <QIODevice>
#include <QFile>
#include <QList>
#include <QDebug>
#include "receiver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Receiver rec1;
    return app.exec();
}
