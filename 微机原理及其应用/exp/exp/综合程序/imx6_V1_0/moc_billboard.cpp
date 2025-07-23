/****************************************************************************
** Meta object code from reading C++ file 'billboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "billboard/billboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'billboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_billboard_t {
    QByteArrayData data[19];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_billboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_billboard_t qt_meta_stringdata_billboard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "billboard"
QT_MOC_LITERAL(1, 10, 11), // "Preferences"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "typFNT_GB16*"
QT_MOC_LITERAL(4, 36, 5), // "GB_16"
QT_MOC_LITERAL(5, 42, 8), // "charsize"
QT_MOC_LITERAL(6, 51, 4), // "work"
QT_MOC_LITERAL(7, 56, 7), // "workSet"
QT_MOC_LITERAL(8, 64, 5), // "wtime"
QT_MOC_LITERAL(9, 70, 8), // "stopShow"
QT_MOC_LITERAL(10, 79, 20), // "openfilebuttonsignal"
QT_MOC_LITERAL(11, 100, 22), // "openFileButton_clicked"
QT_MOC_LITERAL(12, 123, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(13, 146, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(14, 171, 26), // "on_checkBox_3_stateChanged"
QT_MOC_LITERAL(15, 198, 26), // "on_checkBox_5_stateChanged"
QT_MOC_LITERAL(16, 225, 26), // "on_checkBox_7_stateChanged"
QT_MOC_LITERAL(17, 252, 20), // "buttonPressEventSlot"
QT_MOC_LITERAL(18, 273, 1) // "a"

    },
    "billboard\0Preferences\0\0typFNT_GB16*\0"
    "GB_16\0charsize\0work\0workSet\0wtime\0"
    "stopShow\0openfilebuttonsignal\0"
    "openFileButton_clicked\0on_startButton_clicked\0"
    "on_checkBox_stateChanged\0"
    "on_checkBox_3_stateChanged\0"
    "on_checkBox_5_stateChanged\0"
    "on_checkBox_7_stateChanged\0"
    "buttonPressEventSlot\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_billboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,
       7,    2,   76,    2, 0x06 /* Public */,
       9,    1,   81,    2, 0x06 /* Public */,
      10,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,    4,    5,    6,
    QMetaType::Void, QMetaType::Long, QMetaType::Bool,    8,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   18,

       0        // eod
};

void billboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        billboard *_t = static_cast<billboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Preferences((*reinterpret_cast< typFNT_GB16*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->workSet((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->stopShow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->openfilebuttonsignal(); break;
        case 4: _t->openFileButton_clicked(); break;
        case 5: _t->on_startButton_clicked(); break;
        case 6: _t->on_checkBox_stateChanged(); break;
        case 7: _t->on_checkBox_3_stateChanged(); break;
        case 8: _t->on_checkBox_5_stateChanged(); break;
        case 9: _t->on_checkBox_7_stateChanged(); break;
        case 10: _t->buttonPressEventSlot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (billboard::*_t)(typFNT_GB16 * , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&billboard::Preferences)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (billboard::*_t)(long , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&billboard::workSet)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (billboard::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&billboard::stopShow)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (billboard::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&billboard::openfilebuttonsignal)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject billboard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_billboard.data,
      qt_meta_data_billboard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *billboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *billboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_billboard.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int billboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void billboard::Preferences(typFNT_GB16 * _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void billboard::workSet(long _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void billboard::stopShow(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void billboard::openfilebuttonsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
