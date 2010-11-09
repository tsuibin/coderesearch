#include "clientthread.h"
#include <QAbstractSocket>
#include <QByteArray>
#include <QDataStream>
#include <QDateTime>
#include <QFile>
#include <QHostAddress>
#include <QString>

clientThread::clientThread(int h, QObject *parent) :
	QThread(parent),s(parent) /*s(QAbstractSocket::TcpSocket, parent)*//*, file(parent)*/
{
        blockSize = 0;//块大小
        blockNumber  = 0;//块数量
        s.setSocketDescriptor(h);//设置socket描述符
        connect(&s, SIGNAL(disconnected()), this, SLOT(on_socket_disconnected()));//断开链接处理函数
        connect(&s, SIGNAL(readyRead()), this, SLOT(on_socket_readyRead()));//当数据可读的时候
	connect(&s, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(displaySocketError(QAbstractSocket::SocketError)));




}

void clientThread::proccessData(QByteArray &array)//8个字节
{
        QDataStream in(&array, QIODevice::ReadOnly);//8个字节数据转换为流
	in.setVersion(QDataStream::Qt_4_0);

        quint16 key; // 16bit  64 - 16 = 32 + 16 = 48bit key 2个字节
        QByteArray data; //前2个字节给key 6个自己给data
        in >> key >> data; //16bit存入key 48bit 存入QByteArray
        blockNumber ++;//块数++ 每64bit就是一块
	qDebug() << "BlockNumber " << blockNumber << ", size: " << blockSize+sizeof(qint64) << ".";
	qDebug() << "\tKey: " << key << "\t\tSize: " << data.size() << ".";
	switch(key)
	{
	case 0x0001:		// file name
		fileName = fileName.fromUtf8(data.data(), data.size());
		file.setFileName(fileName);
		if(file.exists(fileName))
		{
			qDebug() << "File was exists. now remove it!";
			file.remove(fileName);
		}
		if(!file.open(QIODevice::WriteOnly))
		{
			qDebug() << "Can not open file " << file.fileName() << ".";
			throw 2;
		}
		break;
	case 0x0002:		// file data
            //以字符串的方式写，每次写6个字符
		file.write(data.data(), data.size());
		file.flush();
		break;
	case 0x0003:		// file EOF
		qDebug() << "File transt finished.";
		file.close();
                s.disconnectFromHost();//断开链接


                //emit finished();
		break;
	default: ;
	}
}

void clientThread::run()
{
	qDebug() << "New connect from " << s.peerAddress().toString() << ":" << s.peerPort() << ".";
        exec();//执行线程，进入主循环
}

void clientThread::on_socket_disconnected()
{
	qDebug() << "socket disconnected.";
	exit();
//	emit finished();
}

void clientThread::on_socket_readyRead()//数据可读的时候的处理函数
{
    //s.bytesAvailable() 获取socket中的数据长度
    //当数据大于等于 64 bit 的时候
    //进入循环体

    qDebug() << "sizeof(qint64)" << sizeof(qint64);
	while(s.bytesAvailable() >= sizeof(quint64))
	{
                if(blockSize == 0) //判断blockSize是否为零 ,第一次为零，每次循环结束后置空为0
		{
                    //判断可读数据大小是否小于64bit
			if(s.bytesAvailable() < sizeof(qint64))
				return;
                        //如果数据不小于64bit 那么开始读数据
                        // 把数据写入blockSize,读64bit
                        //char * data  64bit = 8 8 8 8 8 8 8 8
                        //int p 暂用64bit 8位8 8 8 8,8 8 8 8
                        s.read((char*)&blockSize, sizeof(qint64));
		}
                //如果可读数据大小小于blockSize大小,不足64bit则退出循环
                if(s.bytesAvailable() < blockSize)
			return;
                qDebug() << "每次读取" << blockSize << "大小数据";
                QByteArray data = s.read(blockSize);//读取blockSize大小的数据
                proccessData(data);//分析读到的64bit数据
                blockSize = 0;//置空blockSize
	}
}

void clientThread::displaySocketError(QAbstractSocket::SocketError e)
{
	qDebug() << "Error: socket have error " << e << "\n\t" << s.errorString() << ".";
	qDebug() << "Removed " << file.fileName() << ".";
	if(file.isOpen())
		file.close();
	else
		return;
	if(!file.fileName().isEmpty())
		file.remove(fileName);
	else
		return;
	emit error(2);
	//exit();
}
