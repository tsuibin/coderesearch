#include "nfserver.h"
#include "clientthread.h"


nfServer::nfServer(QObject *parent) :
    QTcpServer(parent)
{

    lab = new QLabel;
    lab->setGeometry(300,100,500,500);
    lab->setText("hello!");
    lab->show();

}

void nfServer::startServer()
{
	listen(QHostAddress::Any, 5234);
	qDebug() << "Server started on port 0.0.0.0:5234";
}

void nfServer::stopServer()
{
	close();
}

void nfServer::incomingConnection(int handle)
{
	clientThread* client = new clientThread(handle, this);
	connect(client, SIGNAL(error(int)), this, SLOT(displayError(int)));
        connect(client, SIGNAL(finished()), this, SLOT(finished()));
	connect(client, SIGNAL(finished()), client, SLOT(deleteLater()));
	client->start();
}

void nfServer::displayError(int e)
{
	qDebug() << "The clientThread have a error. " << e << ".";
}

void nfServer::finished()
{
    img.load("timage.png");
    lab->setPixmap(QPixmap::fromImage(img));
	qDebug() << "a clientThread finished.";
}
