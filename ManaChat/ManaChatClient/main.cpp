#include <QApplication>
#include <QTextCodec>
#include "manachatclient.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        ManeChatClient client;
	client.show();
	return a.exec();
}
