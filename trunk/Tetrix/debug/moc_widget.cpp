/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Mon Dec 21 14:46:09 2009
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      35,    7,    7,    7, 0x08,
      62,    7,    7,    7, 0x08,
      88,    7,    7,    7, 0x08,
     114,    7,    7,    7, 0x08,
     140,    7,    7,    7, 0x08,
     166,    7,    7,    7, 0x08,
     192,    7,    7,    7, 0x08,
     218,    7,    7,    7, 0x08,
     244,    7,    7,    7, 0x08,
     270,    7,    7,    7, 0x08,
     285,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0on_pushButton_11_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0timer_upDate()\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_11_clicked(); break;
        case 1: on_pushButton_10_clicked(); break;
        case 2: on_pushButton_9_clicked(); break;
        case 3: on_pushButton_8_clicked(); break;
        case 4: on_pushButton_7_clicked(); break;
        case 5: on_pushButton_6_clicked(); break;
        case 6: on_pushButton_5_clicked(); break;
        case 7: on_pushButton_4_clicked(); break;
        case 8: on_pushButton_3_clicked(); break;
        case 9: on_pushButton_2_clicked(); break;
        case 10: timer_upDate(); break;
        case 11: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
