#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_udpSocket.bind(8763,QUdpSocket::ShareAddress);
    connect(&this->m_udpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    qDebug() <<"server ok";
}


Widget::~Widget()
{
    delete ui;
}


void Widget::readData()
{
    //qDebug() <<"datagram:";
    QByteArray qba;
    while ( this->m_udpSocket.hasPendingDatagrams()) {
        qba.resize(this->m_udpSocket.pendingDatagramSize());
        this->m_udpSocket.readDatagram(qba.data(),this->m_udpSocket.pendingDatagramSize());
    }
    datagram.append(qba);
   // this->dataSize += datagram.size();

   // qDebug() << "datagram.size()" << datagram.size();

    if (datagram.size() == 1228800)
    {
        QImage tmpImage((uchar *)datagram.data(),640,480,QImage::Format_RGB32);
        ui->label->setPixmap(QPixmap::fromImage(tmpImage));
        qDebug() << tmpImage.size();
        qDebug()<<datagram.size() <<"over";
        datagram.clear();
        dataSize = 0;
    }
}
