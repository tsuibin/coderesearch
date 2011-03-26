#include "videosender.h"
#include <QByteArray>
#include <QImage>
#include <QAbstractSocket>

VideoSender::VideoSender(QObject *parent) :
    QObject(parent)
{
    this->m_udpSocket = new QUdpSocket(this);
    this->m_timer = new QTimer(this);
    connect(this->m_timer,SIGNAL(timeout()),this,SLOT(sendMsg()));
    connect(this->m_udpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(errorMessage(QAbstractSocket::SocketError)));

    connect(this->m_udpSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(writeProcess(qint64)));
    this->m_timer->start(3000);

}

void VideoSender::writeProcess(qint64 size)
{
   // if (size%512 == 0){
  //      qDebug() <<"write:" << size;
   // }
}

void VideoSender::errorMessage(QAbstractSocket::SocketError)
{
   // qDebug() << this->m_udpSocket->errorString();
}
void VideoSender::sendMsg()
{
    QByteArray datagram;
    int si;
    QImage img("460.jpeg");
    int dataSize = img.byteCount();
    int packetCount = dataSize / 512;

    // 640x480x4 / 512 = 2400
    // 320x240x4 / 512 = 600

   // qDebug() << "packetCount:" <<packetCount << "dataSize" << dataSize;

    char *ptr = (char *)img.bits();

    for(int i = 0; i < packetCount; i++){
        datagram.clear();
        datagram.append((ptr + (i * 512) ),512);
        si = this->m_udpSocket->writeDatagram(datagram.data(),datagram.size(),
                                              QHostAddress("192.168.0.141"),8763);
        //qDebug() <<datagram.size() << si <<"sender!";
    }
    qDebug() << "send over!";



}
