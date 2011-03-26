#ifndef ManaChatServer_H
#define ManaChatServer_H

#include <QTcpServer>
#include <QList>
#include <QHash>

class QBuffer;
class QTcpSocket;

class ManaChatServer : public QTcpServer
{
	Q_OBJECT

public:
        ManaChatServer(QObject* parent = 0);
        ~ManaChatServer();

private slots:
	void addConnection();
	void removeConnection();
	void receiveMessage();

private:
	QList<QTcpSocket*> connections;
	QHash<QTcpSocket*, QBuffer*> buffers;
};

#endif // ManaChatServer_H
