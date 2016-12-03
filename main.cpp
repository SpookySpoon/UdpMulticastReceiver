#include <QApplication>
#include "receiverhub.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    Receiver receiver;
    ReceiverHub rec1;
//    ReceiverHub rec2;
//    ReceiverHub rec3;
//    receiver.show();
    return app.exec();
}
