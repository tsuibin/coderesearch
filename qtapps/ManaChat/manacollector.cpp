#include "manacollector.h"

#include <QDebug>
#include <QHostAddress>

ManaCollector::ManaCollector(QObject *parent) :
    QObject(parent)
{

}

void ManaCollector::start()
{
    createServer();
    createClient();
}

void ManaCollector::createServer()
{

    if ( server.listen(QHostAddress::Any, port)){
        qDebug() <<"server ok";
    }else{
        qDebug() <<"false"<<server.errorString();
    }
}

void ManaCollector::createClient()
{

    client.show();
}
