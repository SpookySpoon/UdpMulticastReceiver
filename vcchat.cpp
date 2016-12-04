#include <QThread>
#include <QDir>
#include "vcchat.h"
#include "vftpclient.h"

VCChat::VCChat(QObject *parent)
    :QObject(parent)
{}
QTextStream txtS(stdin);
void ChatWindow::inputToVoid()
{
    printf("<Enter a server adress>");
    QString input=txtS.readLine();
    QStringList serverAdress=input.split(" ");
    if(serverAdress.at(0)=="\\vftp"&&serverAdress.count()==3)
    {
        if(QDir(dPath).exists())
        {
            emit sendServerAdress(input);
        }
        else
        {
            qDebug()<<"Please set a download folder. Example: \"/setDF(\"C:\Program Files\")\".";
            inputToVoid();
        }
    }
    else
    {
        inputToVoid();//Если ввели что то левое то будет гонять себя по кругу
    }
}

void ChatWindow::inputToServer()
{
    QString input=txtS.readLine();
    if(input!="Quit")
    {
        if(input.count()>0)
        {
            emit sendServerInput(input);
        }
        else
        {
            inputToServer();
        }
    }
    else
    {
        emit initDisconnect();
    }
}
