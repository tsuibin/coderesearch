
#ifndef QOPENCVWIDGET_H
#define QOPENCVWIDGET_H

#include <opencv/cv.h>
#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QImage>
#include <stdio.h>

#include <QBuffer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QHostAddress>

class QOpenCVWidget : public QWidget {

    Q_OBJECT

public:
    QOpenCVWidget(QWidget *parent = 0);
    ~QOpenCVWidget(void);
    void putImage(IplImage *, int flag);

    private:
        QLabel *imagelabel;
        QVBoxLayout *layout;
        
        QImage image;
        QTcpSocket tcp_client;
        QByteArray image_data;
        QBuffer buf;
        qint64 writed;
        int filesize;

        void Connection();
        void initBuffer();
        void initServer();
        void initImage();

public slots:
        void SendData(qint64 towrite);

signals:
        void imageReady(qint64);
}; 

#endif
