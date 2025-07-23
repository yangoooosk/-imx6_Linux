/****************************************************************************
** Meta object code from reading C++ file 'tubeNixieThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "trackingcar/tubeNixieThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tubeNixieThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tubeNixieThread_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tubeNixieThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tubeNixieThread_t qt_meta_stringdata_tubeNixieThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "tubeNixieThread"
QT_MOC_LITERAL(1, 16, 12), // "tubeDataSlot"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "unsigned char*"
QT_MOC_LITERAL(4, 45, 2) // "ch"

    },
    "tubeNixieThread\0tubeDataSlot\0\0"
    "unsigned char*\0ch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tubeNixieThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void tubeNixieThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tubeNixieThread *_t = static_cast<tubeNixieThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tubeDataSlot((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject tubeNixieThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_tubeNixieThread.data,
      qt_meta_data_tubeNixieThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *tubeNixieThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tubeNixieThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tubeNixieThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int tubeNixieThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_trackingComThread_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_trackingComThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_trackingComThread_t qt_meta_stringdata_trackingComThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "trackingComThread"
QT_MOC_LITERAL(1, 18, 14), // "comDataSignals"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "unsigned char*"
QT_MOC_LITERAL(4, 49, 2), // "ch"
QT_MOC_LITERAL(5, 52, 18), // "comDataShowSignals"
QT_MOC_LITERAL(6, 71, 16), // "trackcarWorkSlot"
QT_MOC_LITERAL(7, 88, 1) // "b"

    },
    "trackingComThread\0comDataSignals\0\0"
    "unsigned char*\0ch\0comDataShowSignals\0"
    "trackcarWorkSlot\0b"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_trackingComThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void trackingComThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        trackingComThread *_t = static_cast<trackingComThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->comDataSignals((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        case 1: _t->comDataShowSignals((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        case 2: _t->trackcarWorkSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (trackingComThread::*_t)(unsigned char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trackingComThread::comDataSignals)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (trackingComThread::*_t)(unsigned char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trackingComThread::comDataShowSignals)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject trackingComThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_trackingComThread.data,
      qt_meta_data_trackingComThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *trackingComThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *trackingComThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_trackingComThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int trackingComThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void trackingComThread::comDataSignals(unsigned char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void trackingComThread::comDataShowSignals(unsigned char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
