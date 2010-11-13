/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Mon Dec 21 14:45:59 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 500);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 100, 91, 41));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(480, 40, 71, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 40, 54, 12));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 100, 91, 41));
        pushButton_2->setCheckable(true);
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 150, 91, 41));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(570, 150, 91, 41));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(470, 200, 91, 41));
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(570, 200, 91, 41));
        pushButton_6->setCheckable(true);
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(470, 250, 91, 41));
        pushButton_7->setCheckable(true);
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(570, 250, 91, 41));
        pushButton_8->setCheckable(true);
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(470, 300, 91, 41));
        pushButton_9->setCheckable(true);
        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(570, 300, 91, 41));
        pushButton_10->setCheckable(true);
        pushButton_11 = new QPushButton(Widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(470, 350, 91, 41));
        pushButton_11->setCheckable(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\346\202\250\347\232\204\345\276\227\345\210\206\346\230\257\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "\346\232\202\345\201\234\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Widget", "\351\207\215\346\226\260\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Widget", "\346\233\264\346\224\271\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Widget", "\346\226\271\345\235\227\350\264\264\345\233\276", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Widget", "\347\275\221\346\240\274\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Widget", "\346\226\271\345\235\227\346\217\220\347\244\272", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\345\243\260\351\237\263", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("Widget", "\346\230\257\345\220\246\345\235\240\350\220\275", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\346\226\271\345\235\227", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("Widget", "\346\227\213\350\275\254\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
