/****************************************************************************
** Meta object code from reading C++ file 'fiar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Fiar/fiar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fiar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Fiar_t {
    QByteArrayData data[25];
    char stringdata[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Fiar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Fiar_t qt_meta_stringdata_Fiar = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 8),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 9),
QT_MOC_LITERAL(4, 25, 9),
QT_MOC_LITERAL(5, 35, 12),
QT_MOC_LITERAL(6, 48, 12),
QT_MOC_LITERAL(7, 61, 12),
QT_MOC_LITERAL(8, 74, 2),
QT_MOC_LITERAL(9, 77, 4),
QT_MOC_LITERAL(10, 82, 11),
QT_MOC_LITERAL(11, 94, 11),
QT_MOC_LITERAL(12, 106, 9),
QT_MOC_LITERAL(13, 116, 7),
QT_MOC_LITERAL(14, 124, 3),
QT_MOC_LITERAL(15, 128, 14),
QT_MOC_LITERAL(16, 143, 11),
QT_MOC_LITERAL(17, 155, 12),
QT_MOC_LITERAL(18, 168, 17),
QT_MOC_LITERAL(19, 186, 12),
QT_MOC_LITERAL(20, 199, 10),
QT_MOC_LITERAL(21, 210, 13),
QT_MOC_LITERAL(22, 224, 13),
QT_MOC_LITERAL(23, 238, 11),
QT_MOC_LITERAL(24, 250, 14)
    },
    "Fiar\0leftTime\0\0totalTime\0signalWin\0"
    "signalRegret\0initMyServer\0initMyClient\0"
    "ip\0port\0updateChess\0playerReady\0"
    "startGame\0timeout\0Win\0slotAdmitLosed\0"
    "updateAdmit\0slotGameOver\0slotRegretRequest\0"
    "updateRegret\0slotRegret\0slotSaveBoard\0"
    "slotOpenBoard\0updateBoard\0updateContinue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fiar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       3,    1,  122,    2, 0x06 /* Public */,
       4,    1,  125,    2, 0x06 /* Public */,
       5,    1,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  131,    2, 0x08 /* Private */,
       7,    2,  132,    2, 0x08 /* Private */,
      10,    2,  137,    2, 0x08 /* Private */,
      11,    1,  142,    2, 0x08 /* Private */,
      12,    0,  145,    2, 0x08 /* Private */,
      13,    0,  146,    2, 0x08 /* Private */,
      14,    1,  147,    2, 0x08 /* Private */,
      15,    0,  150,    2, 0x08 /* Private */,
      16,    1,  151,    2, 0x08 /* Private */,
      17,    0,  154,    2, 0x08 /* Private */,
      18,    0,  155,    2, 0x08 /* Private */,
      19,    1,  156,    2, 0x08 /* Private */,
      20,    1,  159,    2, 0x08 /* Private */,
      21,    0,  162,    2, 0x08 /* Private */,
      22,    0,  163,    2, 0x08 /* Private */,
      23,    1,  164,    2, 0x08 /* Private */,
      24,    1,  167,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Fiar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Fiar *_t = static_cast<Fiar *>(_o);
        switch (_id) {
        case 0: _t->leftTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->totalTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalWin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalRegret((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->initMyServer(); break;
        case 5: _t->initMyClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updateChess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->playerReady((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->startGame(); break;
        case 9: _t->timeout(); break;
        case 10: _t->Win((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slotAdmitLosed(); break;
        case 12: _t->updateAdmit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slotGameOver(); break;
        case 14: _t->slotRegretRequest(); break;
        case 15: _t->updateRegret((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->slotRegret((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 17: _t->slotSaveBoard(); break;
        case 18: _t->slotOpenBoard(); break;
        case 19: _t->updateBoard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->updateContinue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Fiar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Fiar::leftTime)) {
                *result = 0;
            }
        }
        {
            typedef void (Fiar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Fiar::totalTime)) {
                *result = 1;
            }
        }
        {
            typedef void (Fiar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Fiar::signalWin)) {
                *result = 2;
            }
        }
        {
            typedef void (Fiar::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Fiar::signalRegret)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Fiar::staticMetaObject = {
    { &Board::staticMetaObject, qt_meta_stringdata_Fiar.data,
      qt_meta_data_Fiar,  qt_static_metacall, 0, 0}
};


const QMetaObject *Fiar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fiar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Fiar.stringdata))
        return static_cast<void*>(const_cast< Fiar*>(this));
    return Board::qt_metacast(_clname);
}

int Fiar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Board::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Fiar::leftTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Fiar::totalTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Fiar::signalWin(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Fiar::signalRegret(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
