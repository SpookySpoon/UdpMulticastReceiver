#pragma once
#include <QThread>
#include "receiver.h"
#include "vcchat.h"


class VftpClient
{
    QThread threadChat;
    QThread threadClient;
    Receiver client;
    VCChat cWindow;
public:
    ChatClient();
};
