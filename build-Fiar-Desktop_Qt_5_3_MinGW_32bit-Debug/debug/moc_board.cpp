/****************************************************************************
** Meta object code from reading C++ file 'board.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Fiar/board.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Board_t {
    QByteArrayData data[15];
    char stringdata[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Board_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Board_t qt_meta_stringdata_Board = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 12),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 9),
QT_MOC_LITERAL(4, 30, 10),
QT_MOC_LITERAL(5, 41, 13),
QT_MOC_LITERAL(6, 55, 9),
QT_MOC_LITERAL(7, 65, 9),
QT_MOC_LITERAL(8, 75, 23),
QT_MOC_LITERAL(9, 99, 19),
QT_MOC_LITERAL(10, 119, 20),
QT_MOC_LITERAL(11, 140, 17),
QT_MOC_LITERAL(12, 158, 20),
QT_MOC_LITERAL(13, 179, 21),
QT_MOC_LITERAL(14, 201, 20)
    },
    "Board\0initMyClient\0\0gameReady\0admitLosed\0"
    "regretRequest\0saveBoard\0openBoard\0"
    "on_CreateServer_clicked\0on_JoinRoom_clicked\0"
    "on_StartGame_clicked\0on_Regret_clicked\0"
    "on_SaveBoard_clicked\0on_AdmitLoser_clicked\0"
    "on_OpenBoard_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Board[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       3,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,
       7,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Board *_t = static_cast<Board *>(_o);
        switch (_id) {
        case 0: _t->initMyClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->gameReady((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->admitLosed(); break;
        case 3: _t->regretRequest(); break;
        case 4: _t->saveBoard(); break;
        case 5: _t->openBoard(); break;
        case 6: _t->on_CreateServer_clicked(); break;
        case 7: _t->on_JoinRoom_clicked(); break;
        case 8: _t->on_StartGame_clicked(); break;
        case 9: _t->on_Regret_clicked(); break;
        case 10: _t->on_SaveBoard_clicked(); break;
        case 11: _t->on_AdmitLoser_clicked(); break;
        case 12: _t->on_OpenBoard_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Board::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::initMyClient)) {
                *result = 0;
            }
        }
        {
            typedef void (Board::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::gameReady)) {
                *result = 1;
            }
        }
        {
            typedef void (Board::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::admitLosed)) {
                *result = 2;
            }
        }
        {
            typedef void (Board::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::regretRequest)) {
                *result = 3;
            }
        }
        {
            typedef void (Board::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::saveBoard)) {
                *result = 4;
            }
        }
        {
            typedef void (Board::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::openBoard)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Board::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Board.data,
      qt_meta_data_Board,  qt_static_metacall, 0, 0}
};


const QMetaObject *Board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Board::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Board.stringdata))
        return static_cast<void*>(const_cast< Board*>(this));
    return QDialog::qt_metacast(_clname);
}

int Board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Board::initMyClient(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Board::gameReady(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Board::admitLosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Board::regretRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Board::saveBoard()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Board::openBoard()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
