#include "imageserver.h"
#include "ui_imageserver.h"

ImageServer::ImageServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageServer)
{
    ui->setupUi(this);
}

ImageServer::~ImageServer()
{
    delete ui;
}

void ImageServer::on_pushButton_clicked()
{
    if ( m_tcpServer.listen(QHostAddress::Any,8763) == true ){
        qDebug() << "Listen 8763";
    }else{
        qDebug() << "Listen Error!";
    }

    connect(&m_tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnect()));
}

void ImageServer::acceptConnect()
{
    qDebug() << "connected!";
    m_tcpSocket = m_tcpServer.nextPendingConnection();
    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    size = 0;
    data.clear();
}

void ImageServer::readData()
{
    if ( size == 0 ){
        m_tcpSocket->read((char *)&size,sizeof(qint64));
        qDebug() << "package size is :" << size;

    }

    data += m_tcpSocket->readAll();
    m_tcpSocket->flush();
    qDebug() << "data size" << data.size();

    if (size == data.size()){
        qDebug() <<"read over! size is " << data.size();

        QImage tmpImage((uchar *)data.data(),300,400,QImage::Format_RGB32);
        ui->label->setPixmap(QPixmap::fromImage(tmpImage));

        data.clear();
    }

}
