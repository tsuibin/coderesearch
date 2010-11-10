#include "imageclient.h"
#include "ui_imageclient.h"

ImageClient::ImageClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageClient)
{
    ui->setupUi(this);
}

ImageClient::~ImageClient()
{

    delete ui;
}

void ImageClient::on_pushButton_clicked()
{
    m_clientSocket.connectToHost(ui->lineEdit->text(),8763);
    connect(&m_clientSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(mystateChanged(QAbstractSocket::SocketState)));
}

void ImageClient::mystateChanged(QAbstractSocket::SocketState  e)
{
    qDebug() << e << m_clientSocket.errorString();
}


void ImageClient::on_pushButton_2_clicked()
{
    QImage image("yilai.png"); // 348 229
    qDebug() << image.byteCount() << image.size();
    qint64 size = image.byteCount();
image.numBytes()

    data.append((char *)image.bits(),image.byteCount());

    qDebug() << "data size is:" <<data.size();

    m_clientSocket.write((char *)&size,sizeof(qint64));

    m_clientSocket.write(data);
    if ( !m_clientSocket.waitForBytesWritten(-1) ){
        qDebug() << "write data error!";
    }
    m_clientSocket.flush();
    qDebug() << "send over";
}
