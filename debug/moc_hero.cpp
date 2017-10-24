/****************************************************************************
** Meta object code from reading C++ file 'hero.h'
**
** Created: Mon 23. Oct 15:28:36 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hero.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hero.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Hero[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      17,    5,    5,    5, 0x0a,
      24,    5,    5,    5, 0x0a,
      31,    5,    5,    5, 0x0a,
      41,    5,    5,    5, 0x0a,
      56,    5,   51,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Hero[] = {
    "Hero\0\0animator()\0move()\0jump()\0reverse()\0"
    "actions()\0type\0getType()\0"
};

const QMetaObject Hero::staticMetaObject = {
    { &MoovableObjects::staticMetaObject, qt_meta_stringdata_Hero,
      qt_meta_data_Hero, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Hero::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Hero::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Hero::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Hero))
        return static_cast<void*>(const_cast< Hero*>(this));
    return MoovableObjects::qt_metacast(_clname);
}

int Hero::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MoovableObjects::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: animator(); break;
        case 1: move(); break;
        case 2: jump(); break;
        case 3: reverse(); break;
        case 4: actions(); break;
        case 5: { type _r = getType();
            if (_a[0]) *reinterpret_cast< type*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
