/****************************************************************************
** Meta object code from reading C++ file 'videosender.h'
**
** Created: Wed Mar 23 15:14:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "videosender.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videosender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VideoSender[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      25,   23,   12,   12, 0x0a,
      73,   68,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VideoSender[] = {
    "VideoSender\0\0sendMsg()\0e\0"
    "errorMessage(QAbstractSocket::SocketError)\0"
    "size\0writeProcess(qint64)\0"
};

const QMetaObject VideoSender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VideoSender,
      qt_meta_data_VideoSender, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VideoSender::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VideoSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VideoSender::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoSender))
        return static_cast<void*>(const_cast< VideoSender*>(this));
    return QObject::qt_metacast(_clname);
}

int VideoSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendMsg(); break;
        case 1: errorMessage((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: writeProcess((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
