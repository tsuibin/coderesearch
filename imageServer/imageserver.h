#ifndef IMAGESERVER_H
#define IMAGESERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QImage>

namespace Ui {
    class ImageServer;
}

class ImageServer : public QWidget
{
    Q_OBJECT

public:
    explicit ImageServer(QWidget *parent = 0);
    ~ImageServer();

private:
    Ui::ImageServer *ui;

    qint64 size;
    qint64 width;
    qint64 height;
    QTcpServer m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QByteArray data;

private slots:
    void on_pushButton_clicked();
    void acceptConnect();
    void readData();

};

#endif // IMAGESERVER_H
