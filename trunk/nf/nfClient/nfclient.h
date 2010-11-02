#ifndef NFCLIENT_H
#define NFCLIENT_H

#include <QAbstractSocket>
#include <QTcpSocket>

class nfClient : public QTcpSocket//QAbstractSocket
{
    Q_OBJECT
public:
    explicit nfClient(QObject *parent = 0);

	void sendFile(const QString& file, const QHostAddress& dest);
	void sendFile(const QString& file, const QString& dest);
	void sendEOF();

signals:
	void fileSize(qint64 size);
	void message(const QString& str);
	void onError(qint32);

public slots:
	void on_connected();
	void displaySocketError(QAbstractSocket::SocketError e);

private:
	QString filePath;

};

#endif // NFCLIENT_H
