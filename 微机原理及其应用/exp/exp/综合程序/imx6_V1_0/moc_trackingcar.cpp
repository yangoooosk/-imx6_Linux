/****************************************************************************
** Meta object code from reading C++ file 'trackingcar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "trackingcar/trackingcar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackingcar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_trackingCar_t {
    QByteArrayData data[17];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_trackingCar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_trackingCar_t qt_meta_stringdata_trackingCar = {
    {
QT_MOC_LITERAL(0, 0, 11), // "trackingCar"
QT_MOC_LITERAL(1, 12, 11), // "startSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "sta"
QT_MOC_LITERAL(4, 29, 13), // "drawingFinish"
QT_MOC_LITERAL(5, 43, 1), // "e"
QT_MOC_LITERAL(6, 45, 14), // "tubeDataSignal"
QT_MOC_LITERAL(7, 60, 1), // "n"
QT_MOC_LITERAL(8, 62, 18), // "trackcarWorkSignal"
QT_MOC_LITERAL(9, 81, 1), // "b"
QT_MOC_LITERAL(10, 83, 11), // "timerUpDate"
QT_MOC_LITERAL(11, 95, 14), // "unsigned char*"
QT_MOC_LITERAL(12, 110, 1), // "s"
QT_MOC_LITERAL(13, 112, 11), // "comDataSlot"
QT_MOC_LITERAL(14, 124, 2), // "ch"
QT_MOC_LITERAL(15, 127, 18), // "trackcarSwitchSlot"
QT_MOC_LITERAL(16, 146, 22) // "on_startButton_clicked"

    },
    "trackingCar\0startSignal\0\0sta\0drawingFinish\0"
    "e\0tubeDataSignal\0n\0trackcarWorkSignal\0"
    "b\0timerUpDate\0unsigned char*\0s\0"
    "comDataSlot\0ch\0trackcarSwitchSlot\0"
    "on_startButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_trackingCar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   66,    2, 0x0a /* Public */,
      13,    1,   69,    2, 0x0a /* Public */,
      15,    1,   72,    2, 0x0a /* Public */,
      16,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   14,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void trackingCar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        trackingCar *_t = static_cast<trackingCar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->drawingFinish((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->tubeDataSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->trackcarWorkSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->timerUpDate((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        case 5: _t->comDataSlot((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        case 6: _t->trackcarSwitchSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_startButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (trackingCar::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trackingCar::startSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (trackingCar::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trackingCar::drawingFinish)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (trackingCar::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trackingCar::tubeDataSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (trackingCar::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trackingCar::trackcarWorkSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject trackingCar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_trackingCar.data,
      qt_meta_data_trackingCar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *trackingCar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *trackingCar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_trackingCar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int trackingCar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void trackingCar::startSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void trackingCar::drawingFinish(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void trackingCar::tubeDataSignal(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void trackingCar::trackcarWorkSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
