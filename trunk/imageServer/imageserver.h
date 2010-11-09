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
    QTcpServer m_tcpServer;
    QTcpSocket *m_tcpSocket;
    qint64 size;
    QByteArray data;

private slots:
    void on_pushButton_clicked();
    void acceptConnect();
    void readData();

};

#endif // IMAGESERVER_H
