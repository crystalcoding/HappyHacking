/****************************************************************************
** Meta object code from reading C++ file 'myqtapp.h'
**
** Created: Thu May 28 18:18:51 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myqtapp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myqtapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myQtApp[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      19,    8,    8,    8, 0x0a,
      33,    8,    8,    8, 0x0a,
      41,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myQtApp[] = {
    "myQtApp\0\0getPath()\0doSomething()\0"
    "clear()\0about()\0"
};

const QMetaObject myQtApp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_myQtApp,
      qt_meta_data_myQtApp, 0 }
};

const QMetaObject *myQtApp::metaObject() const
{
    return &staticMetaObject;
}

void *myQtApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myQtApp))
        return static_cast<void*>(const_cast< myQtApp*>(this));
    return QDialog::qt_metacast(_clname);
}

int myQtApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getPath(); break;
        case 1: doSomething(); break;
        case 2: clear(); break;
        case 3: about(); break;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
