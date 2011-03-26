#include <QtCore/QCoreApplication>
#include <QUdpSocket>
#include <QTimer>
#include "videosender.h"

/*
class VideoSender :public QObject
{
    Q_OBJECT

public:
    VideoSender() : QObject(0)
    {
        this->m_udpSocket = new QUdpSocket(this);
        this->m_timer = new QTimer(this);
        connect(this->m_timer,SIGNAL(timeout()),this,SLOT(sendMsg()));
    }
    ~VideoSender(){

    }
private slots:
    void sendMsg()
    {
        QByteArray datagram;
        this->m_udpSocket->writeDatagram(datagram.data(),datagram.size(),
                                         QHostAddress::Broadcast,8763);
    }

private:
    QUdpSocket *m_udpSocket;
    QTimer *m_timer;

};
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    VideoSender sender;



    return a.exec();
}
