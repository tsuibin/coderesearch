#ifndef VIDEOSENDER_H
#define VIDEOSENDER_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QDebug>


class VideoSender : public QObject
{
    Q_OBJECT
public:
    explicit VideoSender(QObject *parent = 0);

private slots:
    void sendMsg();
signals:

public slots:
    void errorMessage(QAbstractSocket::SocketError e);
    void writeProcess(qint64 size);

private:
    QUdpSocket *m_udpSocket;
    QTimer *m_timer;

};

#endif // VIDEOSENDER_H
