/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Fiar/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[16];
    char stringdata[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 14),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 5),
QT_MOC_LITERAL(5, 39, 11),
QT_MOC_LITERAL(6, 51, 4),
QT_MOC_LITERAL(7, 56, 7),
QT_MOC_LITERAL(8, 64, 9),
QT_MOC_LITERAL(9, 74, 15),
QT_MOC_LITERAL(10, 90, 16),
QT_MOC_LITERAL(11, 107, 15),
QT_MOC_LITERAL(12, 123, 8),
QT_MOC_LITERAL(13, 132, 18),
QT_MOC_LITERAL(14, 151, 13),
QT_MOC_LITERAL(15, 165, 16)
    },
    "Server\0updateFiarMove\0\0startGame\0write\0"
    "const char*\0data\0maxSize\0byteArray\0"
    "updateFiarAdmit\0updateFiarRegret\0"
    "updateFiarBoard\0gameOver\0updateFiarContinue\0"
    "updateClients\0slotDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       3,    0,   79,    2, 0x06 /* Public */,
       4,    2,   80,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,
       4,    1,   88,    2, 0x06 /* Public */,
       9,    1,   91,    2, 0x06 /* Public */,
      10,    1,   94,    2, 0x06 /* Public */,
      11,    1,   97,    2, 0x06 /* Public */,
      12,    0,  100,    2, 0x06 /* Public */,
      13,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,  104,    2, 0x0a /* Public */,
      15,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::LongLong,    6,    7,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server *_t = static_cast<Server *>(_o);
        switch (_id) {
        case 0: _t->updateFiarMove((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->startGame(); break;
        case 2: _t->write((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->write((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 4: _t->write((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->updateFiarAdmit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updateFiarRegret((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->updateFiarBoard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->gameOver(); break;
        case 9: _t->updateFiarContinue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->updateClients((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->slotDisconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Server::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::updateFiarMove)) {
                *result = 0;
            }
        }
        {
            typedef void (Server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::startGame)) {
                *result = 1;
            }
        }
        {
            typedef void (Server::*_t)(const char * , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::write)) {
                *result = 2;
            }
        }
        {
            typedef void (Server::*_t)(const char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::write)) {
                *result = 3;
            }
        }
        {
            typedef void (Server::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::write)) {
                *result = 4;
            }
        }
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::updateFiarAdmit)) {
                *result = 5;
            }
        }
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::updateFiarRegret)) {
                *result = 6;
            }
        }
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::updateFiarBoard)) {
                *result = 7;
            }
        }
        {
            typedef void (Server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::gameOver)) {
                *result = 8;
            }
        }
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::updateFiarContinue)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject Server::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_Server.data,
      qt_meta_data_Server,  qt_static_metacall, 0, 0}
};


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata))
        return static_cast<void*>(const_cast< Server*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Server::updateFiarMove(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::startGame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Server::write(const char * _t1, qint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Server::write(const char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Server::write(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Server::updateFiarAdmit(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Server::updateFiarRegret(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Server::updateFiarBoard(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Server::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Server::updateFiarContinue(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
