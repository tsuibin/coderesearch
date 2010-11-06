/**************************************************************************
**   
**   Special keywords: tsuibin 11/6/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QImage>

class TcpThread : public QThread
{
    Q_OBJECT
public:
    explicit TcpThread(QTcpSocket *tcpSocket,QObject *parent = 0);
    ~TcpThread();
signals:

public slots:
    void readData();
    void error();
private:
    QTcpSocket *m_tcpSocket;
    void dataProccess(QByteArray array);
    void imageEnd();
    void imageData(QByteArray img);

    QByteArray imageByteArray;
};

#endif // TCPTHREAD_H
