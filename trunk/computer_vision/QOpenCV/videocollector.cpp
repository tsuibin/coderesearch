/**************************************************************************
**   
**   Special keywords: tsuibin 11/7/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "videocollector.h"

VideoCollector::VideoCollector(QObject *parent) :
    QTcpSocket(parent)
{
    connect(this, SIGNAL(connected()), this, SLOT(on_connected()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)),
                    this, SLOT(displaySocketError(QAbstractSocket::SocketError)));



    m_camera = new QCameraDevice(this);
    connect(m_camera, SIGNAL(imageReady(QImage)), this, SLOT(onImageArrival(QImage)));



}


void VideoCollector::sendVideoFrame()
{
    qDebug() << "Send Video Frame ";
        connectToHost(QHostAddress("192.168.0.113"), 8763);

}

void VideoCollector::onImageArrival(QImage image)
{
    //qDebug() << "onImageArrival" <<image.size();
    QByteArray ba;
   // uchar * src = image.bits();
  //  qDebug() << image.byteCount() <<image.size();
    ba.append((char *)image.bits(),image.byteCount());
  //  qDebug() <<ba.size();
    qint64  sizea = ba.size();
    this->write((char *)&sizea,sizeof(qint64));
    this->write(ba);
    if(!this->waitForBytesWritten(-1)) // -1 设置永不超时 只要写错，就报错
    {
            qDebug() << "writen Bytes error " << this->errorString();
    }
    this->flush();

    //this->close();
   // qDebug() << "send over";

}
#define TEST;
void VideoCollector::on_connected()
{

    m_camera->start();

    //链接成功执行
        qDebug() << "Connected";
return;
    #ifdef TEST
        qDebug() << "TEST";
        QImage image("3.png");
        QByteArray ba;
       // uchar * src = image.bits();
        qDebug() << image.byteCount() <<image.size();
        ba.append((char *)image.bits(),image.byteCount());
        qDebug() <<ba.size();
        qint64  sizea = ba.size();
        this->write((char *)&sizea,sizeof(qint64));
        this->write(ba);
        if(!this->waitForBytesWritten(-1)) // -1 设置永不超时 只要写错，就报错
        {
                qDebug() << "writen Bytes error " << this->errorString();
        }
        this->flush();
    #endif
        //this->close();
        qDebug() << "send over";

        return;

//文件QImage 2010 11 2


        QFile file;
//
        //filePath = "3.png"; //image
       // file.setFileName(filePath);
//        file.open(QIODevice::ReadWrite);

//        if (!image.save(&file,"PNG")) return;



//文件QImage 2010 11 2

        if(!file.open(QIODevice::ReadOnly))//如果文件打开失败
        {
                //emit onError(2);
                disconnectFromHost(); //返回错误信息，断开服务器链接
                return;
        }
        else
        {
                //emit fileSize(file.size());//否则发送文件大小信号,用于设置最大字节数和调整进度条范围
        }

        QString frameName = "test video";

        qint64 size;
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        //前两字节是格式控制 :文件名 ,文件正文,文件结尾 后6字节是数据
        out << qint16(0x0001) << "";
        size = block.size();//数据块的大小

        write((char*)&size, sizeof(qint64));//先写64bit数据 也就是8字节 这8字节是block的大小
        write(block.data(), size);//开始写数据,数据最开始2字节是 0x0001 表明这是文件名, 第二个参数是这个数据的长度
        //flush();

        if(!waitForBytesWritten(-1)) // -1 设置永不超时 只要写错，就报错
        {
                qDebug() << "writen Bytes error " << errorString();
                throw 2;
        }
        do
        {
            //开始文件正文传输
                block.clear();
                out.device()->seek(0);
                out << qint16(0x0002) << file.read(0xFFF0);// 前2字节 表明该数据包是文件正文 0xFFF0 = 10(65520) ~ 63.9k
                size = block.size(); //block是文件正文内容，大小范围0~64K
                qDebug() << "Send Data " << size << " byte.";

                write((char*)&size, sizeof(qint64));//先发数据包大小
                write(block.data(), size);//再发数据包
                if(!waitForBytesWritten(-1))//永不超时，只要写错误，就报错 抛出异常
                {
                        qDebug() << "writen Bytes error " << errorString();
                        throw 2;
                }
        }while(!file.atEnd());//直到把文件写完

        sendVideoFrameEOF();//发送文件写完数据包


        qDebug() << "video frame send finished.";
       // emit message(tr(" Send Frame finished!"));
        forever/*(int i=0; i < 10; i++)*/
        {
                if(!waitForDisconnected())
                {
                        //sendEOF();
                }
                else
                {
                        //qDebug() << "Number is " << i << ".";
                        qDebug() << "GoTo return.";
                        return;
                }
        }
        qDebug() << "I will disconnected.";
        disconnectFromHost();	// have Error.
}

void VideoCollector::displaySocketError(QAbstractSocket::SocketError e)
{
        qDebug() << "Error: " << e << "\n\t" << errorString();
        if(e == QAbstractSocket::HostNotFoundError)
            qDebug() << "HostNotFoundError";
                //emit onError(1);
        if(e == QAbstractSocket::ConnectionRefusedError)
            qDebug() << "ConnectionRefusedError";
                //emit onError(3);
}

void VideoCollector::sendVideoFrameEOF()
{
        qint64 size;
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);

        QByteArray data = "video over";
        data.resize(0x8000);//0x8000 = 10(32768) = 32位 4字节
        out << quint16(0x0006) << data << "video over";//前两字节表明该包是文件发送完成 data是4字节文件名数据 最后是文件名
        size = block.size();//获取该包大小
        write((char*)&size, sizeof(qint64));//发送包大小
        write(block.data(), size);//发送包数据
        if(!waitForBytesWritten(-1))//用不超时
                qDebug() << "Send EOF Error: " << errorString();
        else
                qDebug() << "Send EOF";
}
