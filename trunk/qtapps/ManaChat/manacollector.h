#ifndef MANACOLLECTOR_H
#define MANACOLLECTOR_H

#include <QObject>
#include <QHostAddress>
#include "manachatclient.h"
#include "manachatserver.h"

class ManaCollector : public QObject
{
    Q_OBJECT
public:
    explicit ManaCollector(QObject *parent = 0);
    int port;
    void start();

signals:

public slots:
private:
    ManaChatServer server;
    ManeChatClient client;

    void createServer();
    void createClient();

};

#endif // MANACOLLECTOR_H
