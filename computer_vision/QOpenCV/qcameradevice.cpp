/**************************************************************************
**   
**   Special keywords: tsuibin 11/5/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/


#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QChar>

#include "qcameradevice.h"

QCameraDevice::QCameraDevice(QObject *parent) : QObject(parent)
{
    m_capture = new cv::VideoCapture;

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}


QCameraDevice::~QCameraDevice()
{
    delete m_capture;
    m_capture = NULL;
}


bool QCameraDevice::start()
{
    if (m_capture->isOpened()) {
        return true;
    }
    m_capture->open(CV_CAP_ANY);
    if (m_capture->isOpened()) {
        m_timer->start(1000);
    }
    return m_capture->isOpened();
}

bool QCameraDevice::stop()
{
    if (m_capture->isOpened()) {
        m_capture->release();
    }

    return true;
}

void QCameraDevice::onTimeout()
{
    if (!m_capture->isOpened()) {
        return;
    }
    static cv::Mat frame;
    *m_capture >> frame;
    if (frame.cols) {
        emit imageReady(imageFromMat(frame));
    }
}


QImage QCameraDevice::imageFromMat(const cv::Mat &frame)
{
    const unsigned char* src = frame.ptr();
    QImage image(frame.cols, frame.rows, QImage::Format_RGB32);
    unsigned char * des = image.bits();
    unsigned long count = frame.cols * frame.rows;
    for (unsigned long i = 0; i < count; ++i)
    {
        *des++ = *src++; //r
        *des++ = *src++; //g
        *des++ = *src++; //b
        *des++ = 0;//0xff; //255
    }
    return image;
}

