/****************************************************************************
** Meta object code from reading C++ file 'mainwindowuser.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindowuser.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14MainWindowUserE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindowUser::qt_create_metaobjectdata<qt_meta_tag_ZN14MainWindowUserE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindowUser",
        "on_LogOutButton_clicked",
        "",
        "on_RenewButton_clicked",
        "on_LastNewsButton_clicked",
        "on_ReturnButton_clicked",
        "handleBorrow",
        "row",
        "QList<Book*>",
        "books",
        "User*",
        "user",
        "handleReserve",
        "handleRenew",
        "handleReturn",
        "handleClaim",
        "on_BooksButton_clicked",
        "on_HomeButton_clicked",
        "on_HistoryButton_clicked",
        "on_AboutButton_clicked",
        "on_ListOfBorrowedBooksButton_clicked",
        "on_ListOfReservedBooksButton_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_LogOutButton_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_RenewButton_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_LastNewsButton_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ReturnButton_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleBorrow'
        QtMocHelpers::SlotData<void(int, QList<Book*>, User *)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Slot 'handleReserve'
        QtMocHelpers::SlotData<void(int, QList<Book*>, User *)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Slot 'handleRenew'
        QtMocHelpers::SlotData<void(int, QList<Book*>, User *)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Slot 'handleReturn'
        QtMocHelpers::SlotData<void(int, QList<Book*>, User *)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Slot 'handleClaim'
        QtMocHelpers::SlotData<void(int, QList<Book*>, User *)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Slot 'on_BooksButton_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_HomeButton_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_HistoryButton_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_AboutButton_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ListOfBorrowedBooksButton_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ListOfReservedBooksButton_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindowUser, qt_meta_tag_ZN14MainWindowUserE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindowUser::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainWindowUserE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainWindowUserE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14MainWindowUserE_t>.metaTypes,
    nullptr
} };

void MainWindowUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindowUser *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_LogOutButton_clicked(); break;
        case 1: _t->on_RenewButton_clicked(); break;
        case 2: _t->on_LastNewsButton_clicked(); break;
        case 3: _t->on_ReturnButton_clicked(); break;
        case 4: _t->handleBorrow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<Book*>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<User*>>(_a[3]))); break;
        case 5: _t->handleReserve((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<Book*>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<User*>>(_a[3]))); break;
        case 6: _t->handleRenew((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<Book*>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<User*>>(_a[3]))); break;
        case 7: _t->handleReturn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<Book*>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<User*>>(_a[3]))); break;
        case 8: _t->handleClaim((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<Book*>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<User*>>(_a[3]))); break;
        case 9: _t->on_BooksButton_clicked(); break;
        case 10: _t->on_HomeButton_clicked(); break;
        case 11: _t->on_HistoryButton_clicked(); break;
        case 12: _t->on_AboutButton_clicked(); break;
        case 13: _t->on_ListOfBorrowedBooksButton_clicked(); break;
        case 14: _t->on_ListOfReservedBooksButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindowUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowUser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainWindowUserE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
