/**************************************************************************
**   
**   Special keywords: tsuibin 11/7/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef VIDEOCOLLECTOR_H
#define VIDEOCOLLECTOR_H

#include <QTcpSocket>
#include <QHostAddress>


#include <QFile>
#include <QImage>

#include "qcameradevice.h"

class VideoCollector : public QTcpSocket
{
    Q_OBJECT
public:
    explicit VideoCollector(QObject *parent = 0);
    void sendVideoFrame();
    QCameraDevice *m_camera;

signals:

public slots:
    void on_connected();
    void displaySocketError(QAbstractSocket::SocketError e);
    void onImageArrival(QImage image);
private:
    void sendVideoFrameEOF();

};

#endif // VIDEOCOLLECTOR_H
