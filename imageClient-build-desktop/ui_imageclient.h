/********************************************************************************
** Form generated from reading UI file 'imageclient.ui'
**
** Created: Tue Nov 9 15:21:55 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGECLIENT_H
#define UI_IMAGECLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageClient
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *ImageClient)
    {
        if (ImageClient->objectName().isEmpty())
            ImageClient->setObjectName(QString::fromUtf8("ImageClient"));
        ImageClient->resize(400, 300);
        pushButton = new QPushButton(ImageClient);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 40, 85, 27));
        pushButton_2 = new QPushButton(ImageClient);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 110, 85, 27));
        lineEdit = new QLineEdit(ImageClient);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 40, 201, 31));
        label = new QLabel(ImageClient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 101, 16));

        retranslateUi(ImageClient);

        QMetaObject::connectSlotsByName(ImageClient);
    } // setupUi

    void retranslateUi(QWidget *ImageClient)
    {
        ImageClient->setWindowTitle(QApplication::translate("ImageClient", "ImageClient", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ImageClient", "Connect", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ImageClient", "Send", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ImageClient", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ImageClient", "Server Address:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageClient: public Ui_ImageClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGECLIENT_H
