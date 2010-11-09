//#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
#include "nfserver.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	nfServer ser;
	ser.startServer();
    return a.exec();
}
