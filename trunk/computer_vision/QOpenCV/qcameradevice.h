/**************************************************************************
**   
**   Special keywords: tsuibin 11/5/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef QCAMERADEVICE_H
#define QCAMERADEVICE_H

#include <QObject>
#include <QImage>
#include <QTimer>

#include "opencv/cv.h"
#include "opencv/highgui.h"

class QBuffer;
class QTcpSocket;

class QCameraDevice : public QObject
{
    Q_OBJECT
public:
    explicit QCameraDevice(QObject *parent = 0);
    ~QCameraDevice();

signals:
    void imageReady(const QImage& image);

public slots:
    bool start();
    bool stop();

private slots:
    void onTimeout();


private:
    QImage imageFromMat(const cv::Mat& frame);
    cv::VideoCapture * m_capture;
    QTimer * m_timer;
};

#endif // QCAMERADEVICE_H
