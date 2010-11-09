#ifndef NFSERVER_H
#define NFSERVER_H

#include <QTcpServer>
#include <QLabel>

class nfServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit nfServer(QObject *parent = 0);

	void startServer();
	void stopServer();

protected:
	void incomingConnection(int handle);
        QLabel *lab;
        QImage img;

signals:

public slots:
	void displayError(int);
	void finished();

};

#endif // NFSERVER_H
