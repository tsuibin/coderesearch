#include <QCoreApplication>
#include <QHostAddress>
#include <QTextCodec>
#include "manachatserver.h"

static const quint16 DEFAULT_PORT = 8763;

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	quint16 port = 0;
	bool ok = false;
	if (argc > 0)
	{
		port = QString(argv[0]).toInt(&ok);
	}
	if (!ok)
	{
		port = DEFAULT_PORT;
	}
        ManaChatServer server;
	server.listen(QHostAddress::Any, port);
	return a.exec();
}
