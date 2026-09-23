/****************************************************************************
** Meta object code from reading C++ file 'networkprofil.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "networkprofil.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkprofil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_NewtworkProfil_t {
    uint offsetsAndSizes[30];
    char stringdata0[15];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[13];
    char stringdata5[4];
    char stringdata6[11];
    char stringdata7[4];
    char stringdata8[4];
    char stringdata9[5];
    char stringdata10[17];
    char stringdata11[18];
    char stringdata12[10];
    char stringdata13[3];
    char stringdata14[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_NewtworkProfil_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_NewtworkProfil_t qt_meta_stringdata_NewtworkProfil = {
    {
        QT_MOC_LITERAL(0, 14),  // "NewtworkProfil"
        QT_MOC_LITERAL(15, 17),  // "networkProfilLoad"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 13),  // "multicastJoin"
        QT_MOC_LITERAL(48, 12),  // "stringToBool"
        QT_MOC_LITERAL(61, 3),  // "str"
        QT_MOC_LITERAL(65, 10),  // "ayniSubnet"
        QT_MOC_LITERAL(76, 3),  // "ip1"
        QT_MOC_LITERAL(80, 3),  // "ip2"
        QT_MOC_LITERAL(84, 4),  // "mask"
        QT_MOC_LITERAL(89, 16),  // "udpServerGetSlot"
        QT_MOC_LITERAL(106, 17),  // "networkProfilSave"
        QT_MOC_LITERAL(124, 9),  // "NetProfil"
        QT_MOC_LITERAL(134, 2),  // "np"
        QT_MOC_LITERAL(137, 24)   // "hostAddressMacButtonSlot"
    },
    "NewtworkProfil",
    "networkProfilLoad",
    "",
    "multicastJoin",
    "stringToBool",
    "str",
    "ayniSubnet",
    "ip1",
    "ip2",
    "mask",
    "udpServerGetSlot",
    "networkProfilSave",
    "NetProfil",
    "np",
    "hostAddressMacButtonSlot"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_NewtworkProfil[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    1,   58,    2, 0x0a,    3 /* Public */,
       6,    3,   61,    2, 0x0a,    5 /* Public */,
      10,    0,   68,    2, 0x08,    9 /* Private */,
      11,    1,   69,    2, 0x08,   10 /* Private */,
      14,    0,   72,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject NewtworkProfil::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NewtworkProfil.offsetsAndSizes,
    qt_meta_data_NewtworkProfil,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_NewtworkProfil_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NewtworkProfil, std::true_type>,
        // method 'networkProfilLoad'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'multicastJoin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stringToBool'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'ayniSubnet'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'udpServerGetSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'networkProfilSave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<NetProfil, std::false_type>,
        // method 'hostAddressMacButtonSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NewtworkProfil::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewtworkProfil *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->networkProfilLoad(); break;
        case 1: _t->multicastJoin(); break;
        case 2: { bool _r = _t->stringToBool((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->ayniSubnet((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->udpServerGetSlot(); break;
        case 5: _t->networkProfilSave((*reinterpret_cast< std::add_pointer_t<NetProfil>>(_a[1]))); break;
        case 6: _t->hostAddressMacButtonSlot(); break;
        default: ;
        }
    }
}

const QMetaObject *NewtworkProfil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewtworkProfil::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewtworkProfil.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NewtworkProfil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
