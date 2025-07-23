/****************************************************************************
** Meta object code from reading C++ file 'itms.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "itms/itms.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'itms.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ITMS_t {
    QByteArrayData data[19];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ITMS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ITMS_t qt_meta_stringdata_ITMS = {
    {
QT_MOC_LITERAL(0, 0, 4), // "ITMS"
QT_MOC_LITERAL(1, 5, 7), // "busPass"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 11), // "setShowData"
QT_MOC_LITERAL(4, 26, 14), // "bustimeoutSlot"
QT_MOC_LITERAL(5, 41, 19), // "norsouthtimeoutSlot"
QT_MOC_LITERAL(6, 61, 19), // "eastwesttimeoutSlot"
QT_MOC_LITERAL(7, 81, 15), // "arrivalTimeSlot"
QT_MOC_LITERAL(8, 97, 11), // "stopBusPass"
QT_MOC_LITERAL(9, 109, 11), // "comPollSlot"
QT_MOC_LITERAL(10, 121, 15), // "setShowDataSlot"
QT_MOC_LITERAL(11, 137, 11), // "comDataSlot"
QT_MOC_LITERAL(12, 149, 14), // "itmsSwitchSlot"
QT_MOC_LITERAL(13, 164, 1), // "n"
QT_MOC_LITERAL(14, 166, 21), // "on_itmsButton_clicked"
QT_MOC_LITERAL(15, 188, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(16, 213, 26), // "on_checkBox_2_stateChanged"
QT_MOC_LITERAL(17, 240, 26), // "on_checkBox_3_stateChanged"
QT_MOC_LITERAL(18, 267, 26) // "on_checkBox_4_stateChanged"

    },
    "ITMS\0busPass\0\0setShowData\0bustimeoutSlot\0"
    "norsouthtimeoutSlot\0eastwesttimeoutSlot\0"
    "arrivalTimeSlot\0stopBusPass\0comPollSlot\0"
    "setShowDataSlot\0comDataSlot\0itmsSwitchSlot\0"
    "n\0on_itmsButton_clicked\0"
    "on_checkBox_stateChanged\0"
    "on_checkBox_2_stateChanged\0"
    "on_checkBox_3_stateChanged\0"
    "on_checkBox_4_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ITMS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    1,  104,    2, 0x0a /* Public */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ITMS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ITMS *_t = static_cast<ITMS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->busPass(); break;
        case 1: _t->setShowData(); break;
        case 2: _t->bustimeoutSlot(); break;
        case 3: _t->norsouthtimeoutSlot(); break;
        case 4: _t->eastwesttimeoutSlot(); break;
        case 5: _t->arrivalTimeSlot(); break;
        case 6: _t->stopBusPass(); break;
        case 7: _t->comPollSlot(); break;
        case 8: _t->setShowDataSlot(); break;
        case 9: _t->comDataSlot(); break;
        case 10: _t->itmsSwitchSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_itmsButton_clicked(); break;
        case 12: _t->on_checkBox_stateChanged(); break;
        case 13: _t->on_checkBox_2_stateChanged(); break;
        case 14: _t->on_checkBox_3_stateChanged(); break;
        case 15: _t->on_checkBox_4_stateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ITMS::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ITMS::busPass)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ITMS::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ITMS::setShowData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ITMS::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ITMS.data,
      qt_meta_data_ITMS,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ITMS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ITMS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ITMS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ITMS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ITMS::busPass()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ITMS::setShowData()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
