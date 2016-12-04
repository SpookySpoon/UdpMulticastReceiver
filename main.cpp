#include <QApplication>
#include <QIODevice>
#include <QFile>
#include <QList>
#include <QDebug>
#include "receiverhub.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Receiver rec1;
//    QList<QByteArray> dataToTransfer;
//    QFile existingFile("C:/Users/Home/Desktop/Ted Irens - Sunday Breakfast.mp3");
//    existingFile.open(QIODevice::ReadOnly);
//    qDebug()<<"existingFile file bytes awailable: "<<existingFile.bytesAvailable();
//    QByteArray rAll=existingFile.readAll();
//    int byteCount=rAll.count();
//    int packNum=byteCount/5;
//    for (int i =0;i<packNum;i++)
//    {
//        QByteArray tempBytes;
//        for(int i1 =i*5;i1<i*5+5;i1++)
//        {
//            tempBytes.append(rAll[i1]);
//        }
//        dataToTransfer<<tempBytes;
//    }
//    int resid=packNum%5;
//    if (resid>0)
//    {
//        QByteArray lastArray;
//        int position=(packNum-resid+1);

//        for(int i1 =0;i1<resid;i1++)
//        {
//            lastArray.append(rAll[position+i1]);
//        }
//        dataToTransfer<<lastArray;
//    }
//    qDebug()<<"dataToTransfer counssst: "<<dataToTransfer.at(555).count();

//    QFile myFile("C:/Users/Home/Desktop/someTrack.mp3");
//    myFile.open(QIODevice::ReadWrite);

//    qDebug()<<"myFile.isWritable: "<<myFile.isWritable();
//    QByteArray newArray;
//    for (auto i:dataToTransfer)
//    {
//        newArray.append(i);
//    }
//    myFile.write(newArray);
//    qDebug()<<"New file bytes awailable: "<<myFile.bytesAvailable();

//    myFile.close();
//    existingFile.close();
    return app.exec();
}
