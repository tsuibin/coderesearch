#include "nfclient.h"
#include <QByteArray>
#include <QDataStream>
#include <QHostAddress>


nfClient::nfClient(QObject *parent)
	: QTcpSocket(parent)//QAbstractSocket(QAbstractSocket::TcpSocket, parent)
{
	connect(this, SIGNAL(connected()), this, SLOT(on_connected()));
	connect(this, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(displaySocketError(QAbstractSocket::SocketError)));


        //image

}

void nfClient::sendFile(const QString &file, const QHostAddress &dest)
{
    //设置要发送的文件名

	filePath = file;
        //链接到远程服务器
        connectToHost(dest, 5234);
	qDebug() << "Send file " << file;
}

void nfClient::sendFile(const QString &file, const QString &dest)
{
	filePath = file;
	connectToHost(dest, 5234);
	qDebug() << "Send file " << file;
}

void nfClient::on_connected()
{
    //链接成功执行
	qDebug() << "Connected";

//文件QImage 2010 11 2
//        QImage image;
//        image.load("timage.png");
//        image.save("/tmp/timage.png","PNG");

        QFile file;
//
        filePath = "/tmp/timage.png"; //image
        file.setFileName(filePath);
//        file.open(QIODevice::ReadWrite);

//        if (!image.save(&file,"PNG")) return;



//文件QImage 2010 11 2

        if(!file.open(QIODevice::ReadOnly))//如果文件打开失败
        {
                emit onError(2);
                disconnectFromHost(); //返回错误信息，断开服务器链接
                return;
        }
        else
        {
                emit fileSize(file.size());//否则发送文件大小信号,用于设置最大字节数和调整进度条范围
        }
        //emit fileSize(file.size());

	emit message(tr(" Start send!"));
	QString fileName = file.fileName();
        //获取文件名
	fileName = fileName.remove(0, fileName.lastIndexOf('/')+1);

	qint64 size;
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);
        //前两字节是格式控制 :文件名 ,文件正文,文件结尾 后6字节是数据
	out << qint16(0x0001) << fileName.toUtf8();
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

        sendEOF();//发送文件写完数据包


	qDebug() << "FileSend finished.";
	emit message(tr(" Send finished!"));
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

void nfClient::displaySocketError(QAbstractSocket::SocketError e)
{
	qDebug() << "Error: " << e << "\n\t" << errorString();
	if(e == QAbstractSocket::HostNotFoundError)
		emit onError(1);
	if(e == QAbstractSocket::ConnectionRefusedError)
		emit onError(3);
}

void nfClient::sendEOF()
{
	qint64 size;
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);

	QByteArray data = filePath.toUtf8();
        data.resize(0x8000);//0x8000 = 10(32768) = 32位 4字节
        out << quint16(0x0003) << data << filePath.toUtf8();//前两字节表明该包是文件发送完成 data是4字节文件名数据 最后是文件名
        size = block.size();//获取该包大小
        write((char*)&size, sizeof(qint64));//发送包大小
        write(block.data(), size);//发送包数据
        if(!waitForBytesWritten(-1))//用不超时
		qDebug() << "Send EOF Error: " << errorString();
	else
		qDebug() << "Send EOF";
}
