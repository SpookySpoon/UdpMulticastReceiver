#pragma once
#include <QObject>

class VCChat : public QObject
{
    Q_OBJECT
    QString dPath;
public:
    ChatWindow(QObject *parent = nullptr);
public slots:






    void inputToVoid();
    void inputToServer();
signals:
    void setDFolder(const QString&);





    void sendServerAdress(const QString&);
    void sendServerInput(const QString&);
    void initDisconnect();

};
