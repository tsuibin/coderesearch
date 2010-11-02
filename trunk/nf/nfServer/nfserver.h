#ifndef NFSERVER_H
#define NFSERVER_H

#include <QTcpServer>

class nfServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit nfServer(QObject *parent = 0);

	void startServer();
	void stopServer();

protected:
	void incomingConnection(int handle);

signals:

public slots:
	void displayError(int);
	void finished();

};

#endif // NFSERVER_H
