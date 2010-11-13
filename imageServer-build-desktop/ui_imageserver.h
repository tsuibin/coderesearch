/********************************************************************************
** Form generated from reading UI file 'imageserver.ui'
**
** Created: Tue Nov 9 16:49:27 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESERVER_H
#define UI_IMAGESERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageServer
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *ImageServer)
    {
        if (ImageServer->objectName().isEmpty())
            ImageServer->setObjectName(QString::fromUtf8("ImageServer"));
        ImageServer->resize(742, 482);
        pushButton = new QPushButton(ImageServer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 40, 85, 27));
        label = new QLabel(ImageServer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 70, 348, 229));

        retranslateUi(ImageServer);

        QMetaObject::connectSlotsByName(ImageServer);
    } // setupUi

    void retranslateUi(QWidget *ImageServer)
    {
        ImageServer->setWindowTitle(QApplication::translate("ImageServer", "ImageServer", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ImageServer", "Listen", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageServer: public Ui_ImageServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESERVER_H
