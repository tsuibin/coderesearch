#ifndef SIMPLECHATCLIENT_H
#define SIMPLECHATCLIENT_H

#include <QWidget>

class QBuffer;
class QSpinBox;
class QLineEdit;
class QTextEdit;
class QTcpSocket;
class QPushButton;

class ManeChatClient : public QWidget
{
	Q_OBJECT

public:
        ManeChatClient(QWidget* parent = 0, Qt::WFlags flags = 0);
        ~ManeChatClient();

private slots:
	void setConnected();
	void setDisconnected();
	void toggleConnection();
	void sendMessage();
	void receiveMessage();

private:
	
	QBuffer*		buffer;
	QSpinBox*		port;
	QLineEdit*		nick;
	QLineEdit*		server;
	QLineEdit*		message;
	QTextEdit*		chat;
	QTcpSocket*		socket;
	QPushButton*	conn;
	QPushButton*	send;
};

#endif // ManeChatClient_H
