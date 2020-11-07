/****************************************************************************
** Meta object code from reading C++ file 'texteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "texteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'texteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_texteditor_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_texteditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_texteditor_t qt_meta_stringdata_texteditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "texteditor"
QT_MOC_LITERAL(1, 11, 9), // "CreatFile"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "loadFile"
QT_MOC_LITERAL(4, 31, 8), // "filename"
QT_MOC_LITERAL(5, 40, 8), // "openFile"
QT_MOC_LITERAL(6, 49, 4), // "save"
QT_MOC_LITERAL(7, 54, 5), // "about"
QT_MOC_LITERAL(8, 60, 8), // "set_font"
QT_MOC_LITERAL(9, 69, 13), // "set_fontcolor"
QT_MOC_LITERAL(10, 83, 18) // "setBackgroundcolor"

    },
    "texteditor\0CreatFile\0\0loadFile\0filename\0"
    "openFile\0save\0about\0set_font\0set_fontcolor\0"
    "setBackgroundcolor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_texteditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void texteditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<texteditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreatFile(); break;
        case 1: _t->loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->openFile(); break;
        case 3: _t->save(); break;
        case 4: _t->about(); break;
        case 5: _t->set_font(); break;
        case 6: _t->set_fontcolor(); break;
        case 7: _t->setBackgroundcolor(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject texteditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_texteditor.data,
    qt_meta_data_texteditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *texteditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *texteditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_texteditor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int texteditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
