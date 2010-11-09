#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QDateTime>
#include <QFile>
#include <QString>


class clientThread : public QThread
{
    Q_OBJECT
public:
	explicit clientThread(int h, QObject *parent = 0);
	void proccessData(QByteArray& array);


protected:
	void run();

signals:
	void error(int);
        //void finished();

public slots:
	void on_socket_readyRead();
	void on_socket_disconnected();
	void displaySocketError(QAbstractSocket::SocketError e);

private:
	QFile file;
        QString fileName;//文件名
	QTcpSocket s;
        qint64 blockSize;//块大小
        qint64 blockNumber;//块数量

};

#endif // CLIENTTHREAD_H
