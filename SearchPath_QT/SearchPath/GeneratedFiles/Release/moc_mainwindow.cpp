/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata[515];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 19),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 25),
QT_MOC_LITERAL(4, 58, 7),
QT_MOC_LITERAL(5, 66, 23),
QT_MOC_LITERAL(6, 90, 23),
QT_MOC_LITERAL(7, 114, 23),
QT_MOC_LITERAL(8, 138, 29),
QT_MOC_LITERAL(9, 168, 35),
QT_MOC_LITERAL(10, 204, 25),
QT_MOC_LITERAL(11, 230, 25),
QT_MOC_LITERAL(12, 256, 39),
QT_MOC_LITERAL(13, 296, 22),
QT_MOC_LITERAL(14, 319, 30),
QT_MOC_LITERAL(15, 350, 24),
QT_MOC_LITERAL(16, 375, 52),
QT_MOC_LITERAL(17, 428, 30),
QT_MOC_LITERAL(18, 459, 28),
QT_MOC_LITERAL(19, 488, 26)
    },
    "MainWindow\0on_btnStart_clicked\0\0"
    "on_chkShowAllPath_toggled\0checked\0"
    "on_actionQuit_triggered\0on_actionSave_triggered\0"
    "on_actionOpen_triggered\0"
    "on_actionResetStart_triggered\0"
    "on_actionResetDestination_triggered\0"
    "on_actionAddObs_triggered\0"
    "on_actionDelObs_triggered\0"
    "on_actionShowSearchedPathTree_triggered\0"
    "on_actionNew_triggered\0"
    "on_actionClearResult_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionShowSearchedPathTreeWithDistances_triggered\0"
    "on_actionEnlargement_triggered\0"
    "on_actionReduction_triggered\0"
    "on_actionZoom100_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    1,  100,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    1,  106,    2, 0x08 /* Private */,
       9,    1,  109,    2, 0x08 /* Private */,
      10,    1,  112,    2, 0x08 /* Private */,
      11,    1,  115,    2, 0x08 /* Private */,
      12,    1,  118,    2, 0x08 /* Private */,
      13,    0,  121,    2, 0x08 /* Private */,
      14,    1,  122,    2, 0x08 /* Private */,
      15,    0,  125,    2, 0x08 /* Private */,
      16,    1,  126,    2, 0x08 /* Private */,
      17,    0,  129,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    0,  131,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_btnStart_clicked(); break;
        case 1: _t->on_chkShowAllPath_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_actionQuit_triggered(); break;
        case 3: _t->on_actionSave_triggered(); break;
        case 4: _t->on_actionOpen_triggered(); break;
        case 5: _t->on_actionResetStart_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_actionResetDestination_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_actionAddObs_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_actionDelObs_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_actionShowSearchedPathTree_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_actionNew_triggered(); break;
        case 11: _t->on_actionClearResult_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_actionAbout_triggered(); break;
        case 13: _t->on_actionShowSearchedPathTreeWithDistances_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_actionEnlargement_triggered(); break;
        case 15: _t->on_actionReduction_triggered(); break;
        case 16: _t->on_actionZoom100_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
