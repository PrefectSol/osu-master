/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../osu-Manager-Stats/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[28];
    char stringdata4[5];
    char stringdata5[28];
    char stringdata6[8];
    char stringdata7[23];
    char stringdata8[24];
    char stringdata9[33];
    char stringdata10[6];
    char stringdata11[25];
    char stringdata12[4];
    char stringdata13[7];
    char stringdata14[24];
    char stringdata15[26];
    char stringdata16[28];
    char stringdata17[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 20),  // "on_addButton_pressed"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 27),  // "on_rowsSpinBox_valueChanged"
        QT_MOC_LITERAL(61, 4),  // "rows"
        QT_MOC_LITERAL(66, 27),  // "on_colsSpinBox_valueChanged"
        QT_MOC_LITERAL(94, 7),  // "columns"
        QT_MOC_LITERAL(102, 22),  // "on_clearButton_pressed"
        QT_MOC_LITERAL(125, 23),  // "on_chooseButton_pressed"
        QT_MOC_LITERAL(149, 32),  // "on_viewJsonCheckBox_stateChanged"
        QT_MOC_LITERAL(182, 5),  // "state"
        QT_MOC_LITERAL(188, 24),  // "on_userTable_cellClicked"
        QT_MOC_LITERAL(213, 3),  // "row"
        QT_MOC_LITERAL(217, 6),  // "column"
        QT_MOC_LITERAL(224, 23),  // "on_goChoosePage_pressed"
        QT_MOC_LITERAL(248, 25),  // "on_goSettingsPage_pressed"
        QT_MOC_LITERAL(274, 27),  // "on_goOverviewButton_pressed"
        QT_MOC_LITERAL(302, 27)   // "on_removeDataButton_pressed"
    },
    "MainWindow",
    "on_addButton_pressed",
    "",
    "on_rowsSpinBox_valueChanged",
    "rows",
    "on_colsSpinBox_valueChanged",
    "columns",
    "on_clearButton_pressed",
    "on_chooseButton_pressed",
    "on_viewJsonCheckBox_stateChanged",
    "state",
    "on_userTable_cellClicked",
    "row",
    "column",
    "on_goChoosePage_pressed",
    "on_goSettingsPage_pressed",
    "on_goOverviewButton_pressed",
    "on_removeDataButton_pressed"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    1,   81,    2, 0x08,    2 /* Private */,
       5,    1,   84,    2, 0x08,    4 /* Private */,
       7,    0,   87,    2, 0x08,    6 /* Private */,
       8,    0,   88,    2, 0x08,    7 /* Private */,
       9,    1,   89,    2, 0x08,    8 /* Private */,
      11,    2,   92,    2, 0x08,   10 /* Private */,
      14,    0,   97,    2, 0x08,   13 /* Private */,
      15,    0,   98,    2, 0x08,   14 /* Private */,
      16,    0,   99,    2, 0x08,   15 /* Private */,
      17,    0,  100,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_addButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rowsSpinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_colsSpinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_clearButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_chooseButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_viewJsonCheckBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_userTable_cellClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_goChoosePage_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_goSettingsPage_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_goOverviewButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_removeDataButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_addButton_pressed(); break;
        case 1: _t->on_rowsSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_colsSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_clearButton_pressed(); break;
        case 4: _t->on_chooseButton_pressed(); break;
        case 5: _t->on_viewJsonCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_userTable_cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->on_goChoosePage_pressed(); break;
        case 8: _t->on_goSettingsPage_pressed(); break;
        case 9: _t->on_goOverviewButton_pressed(); break;
        case 10: _t->on_removeDataButton_pressed(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
