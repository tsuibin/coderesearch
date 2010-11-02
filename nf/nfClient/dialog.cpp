#include "dialog.h"
#include "ui_dialog.h"
#include "nfclient.h"
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
	sendBytes = 0;
	blockNumber = 0;
	maxBytes = 0;
	cleanQuit = true;
    ui->setupUi(this);
	ui->progressBar->setRange(0, 1000);
	ui->progressBar->setValue(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonBrow_clicked()
{
	ui->lineEditFile->setText(QFileDialog::getOpenFileName(this, tr("Open File"), tr("."), tr("All Files (*)")));
}

void Dialog::on_pushButtonSend_clicked()
{
	cleanQuit = false;
	sendBytes = 0;
	blockNumber = 0;
	maxBytes = 0;
	if(ui->lineEditTag->text().isEmpty() || ui->lineEditFile->text().isEmpty())
	{
		QMessageBox::information(this, tr("Error"), tr("Tag and File can not be empty."));
		return;
	}
	ui->pushButtonSend->setEnabled(false);
	nfClient* client = new nfClient(this);
	connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
	connect(client, SIGNAL(disconnected()), this, SLOT(on_socketDisconnected()));
	connect(client, SIGNAL(fileSize(qint64)), this, SLOT(setProccessBar(qint64)));
	connect(client, SIGNAL(bytesWritten(qint64)), this, SLOT(updateProccessBar(qint64)));
	connect(client, SIGNAL(message(QString)), this, SLOT(updateStatusLabel(QString)));
	connect(client, SIGNAL(onError(qint32)), this, SLOT(on_socketError(qint32)));
	client->sendFile(ui->lineEditFile->text(), ui->lineEditTag->text());
}

void Dialog::updateProccessBar(qint64 v)
{
	blockNumber ++;
	sendBytes += v;
	ui->progressBar->setValue(sendBytes);
	qDebug() << "sended number " << blockNumber << ", cur " << v << ". "
			<< sendBytes << " bytes. total " << maxBytes << " bytes.";
}

void Dialog::updateStatusLabel(const QString &status)
{
	QString st;
	st = "Status: " + status;
	ui->labelStatus->setText(st);
}

void Dialog::setProccessBar(qint64 r)
{
    //收到文件大小信号，设置maxBytes 最大字节数
	maxBytes = r;
        ui->progressBar->setRange(0, r-1);//设置进度条范围0 到最大值减1
}

void Dialog::on_socketDisconnected()
{
	ui->progressBar->setRange(0, 100);
	ui->progressBar->setValue(100);
	ui->pushButtonSend->setEnabled(true);
	cleanQuit = true;
}

void Dialog::on_pushButtonQuit_clicked()
{
	if(cleanQuit)
		close();
	else
	{
		if(QMessageBox::warning(this, tr("Are you sure!"),
							 tr("You have file transting.\nAre you sure you want quit?"),
							 QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok)
			close();
	}
}

void Dialog::on_socketError(qint32 e)
{
	switch(e)
	{
	case 1:
		QMessageBox::warning(this, tr("Error"),
							 QString::fromUtf8("目标名错误!\n请输入有效的主机名或IP地址。"),
							 QMessageBox::Close);
		break;
	case 2:
		QMessageBox::warning(this, tr("Error"),
							 QString::fromUtf8("文件名错误!\n请输入有效的文件名及路径。"),
							 QMessageBox::Close);
		break;
	case 3:
		QMessageBox::warning(this, tr("Error"),
							 QString::fromUtf8("连接目标服务器失败!\n请检查网络连接，如果问题依然存在请联系目标服务器管理员。"),
							 QMessageBox::Close);
	}
	ui->pushButtonSend->setEnabled(true);
}
