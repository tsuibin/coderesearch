#include "manachatserver.h"
#include <QBuffer>
#include <QTcpSocket>

ManaChatServer::ManaChatServer(QObject* parent) : QTcpServer(parent)
{
	connect(this, SIGNAL(newConnection()), this, SLOT(addConnection()));
}

ManaChatServer::~ManaChatServer()
{
}

void ManaChatServer::addConnection()
{
	QTcpSocket* connection = nextPendingConnection();
	connections.append(connection);
	QBuffer* buffer = new QBuffer(this);
	buffer->open(QIODevice::ReadWrite);
	buffers.insert(connection, buffer);
	connect(connection, SIGNAL(disconnected()), SLOT(removeConnection()));
	connect(connection, SIGNAL(readyRead()),	SLOT(receiveMessage()));
}

void ManaChatServer::removeConnection()
{
	QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
	QBuffer* buffer = buffers.take(socket);
	buffer->close();
	buffer->deleteLater();
	connections.removeAll(socket);
	socket->deleteLater();
}

void ManaChatServer::receiveMessage()
{
	QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
	QBuffer* buffer = buffers.value(socket);
	
        qint64 bytes = buffer->write(socket->readAll());
	buffer->seek(buffer->pos() - bytes);
	while (buffer->canReadLine())
	{
		QByteArray line = buffer->readLine();
		foreach (QTcpSocket* connection, connections)
		{
			connection->write(line);
		}
	}
}
