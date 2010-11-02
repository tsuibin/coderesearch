#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
	int sendBytes;
	qint64 blockNumber;
	qint64 maxBytes;
	bool cleanQuit;

private slots:
	void on_pushButtonQuit_clicked();
	void on_pushButtonSend_clicked();
	void on_pushButtonBrow_clicked();
	void updateProccessBar(qint64 v);
	void updateStatusLabel(const QString& status);
	void setProccessBar(qint64 r);
	void on_socketDisconnected();
	void on_socketError(qint32);
};

#endif // DIALOG_H
