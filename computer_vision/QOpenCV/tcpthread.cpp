/**************************************************************************
**   
**   Special keywords: tsuibin 11/6/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "tcpthread.h"

TcpThread::TcpThread(QTcpSocket *tcpSocket,QObject *parent) :
    QThread(parent),m_tcpSocket(tcpSocket)
{


    //connect(m_tcpSocket, SIGNAL(finished()), this, SLOT(deleteLater()));

}
TcpThread::~TcpThread()
{
    delete m_tcpSocket;
}

void TcpThread::error()
{
    qDebug() << m_tcpSocket->errorString();
}
void TcpThread::readData()
{
    qDebug() <<"readdata";
    qint64 blockSize;
    while( m_tcpSocket->bytesAvailable() >= sizeof(qint64)){
        if (m_tcpSocket->bytesAvailable() < sizeof(qint64)) return;

        m_tcpSocket->read((char *)&blockSize,sizeof(qint64));
        //qDebug() << "read data size is " << blockSize;
        if(m_tcpSocket->bytesAvailable() < blockSize ) return;

        QByteArray data = m_tcpSocket->read(blockSize);
        dataProccess(data);
        blockSize = 0;
    }
}

void TcpThread::dataProccess(QByteArray array)
{
    QDataStream in(&array, QIODevice::ReadOnly);//8个字节数据转换为流
    in.setVersion(QDataStream::Qt_4_6);

    qint64 key; // 16bit  64 - 16 = 32 + 16 = 48bit key 2个字节
    QByteArray data; //前2个字节给key 6个自己给data
    in >> key >> data; //16bit存入key 48bit 存入QByteArray
    qDebug() << key << data;
    switch(key){
    case 0x0001:
        break;
    case 0x0002:
        break;
    case 0x0003:
        break;
    case 0x0004:
        break;
    case 0x0005:
            imageData(data);
        break;
    case 0x0006:
            imageEnd();
        break;
    default:
        qDebug() << "package error!";
        break;
    }
}
void TcpThread::imageEnd()
{
    QImage image;
    qDebug () << "image ready!" << image.fromData(imageByteArray).size();
}
void TcpThread::imageData(QByteArray img)
{
    imageByteArray += img;
}
