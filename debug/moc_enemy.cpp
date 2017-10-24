/****************************************************************************
** Meta object code from reading C++ file 'enemy.h'
**
** Created: Mon 23. Oct 16:01:03 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../enemy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enemy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Enemy[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      14,    6,    6,    6, 0x0a,
      23,    6,    6,    6, 0x0a,
      33,    6,    6,    6, 0x0a,
      44,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Enemy[] = {
    "Enemy\0\0move()\0moveUp()\0reverse()\0"
    "animator()\0die()\0"
};

const QMetaObject Enemy::staticMetaObject = {
    { &MoovableObjects::staticMetaObject, qt_meta_stringdata_Enemy,
      qt_meta_data_Enemy, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Enemy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Enemy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Enemy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Enemy))
        return static_cast<void*>(const_cast< Enemy*>(this));
    return MoovableObjects::qt_metacast(_clname);
}

int Enemy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MoovableObjects::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: move(); break;
        case 1: moveUp(); break;
        case 2: reverse(); break;
        case 3: animator(); break;
        case 4: die(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
