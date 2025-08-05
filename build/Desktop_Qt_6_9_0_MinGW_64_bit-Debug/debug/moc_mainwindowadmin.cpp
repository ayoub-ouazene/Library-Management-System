/****************************************************************************
** Meta object code from reading C++ file 'mainwindowadmin.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindowadmin.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowadmin.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15MainWindowAdminE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindowAdmin::qt_create_metaobjectdata<qt_meta_tag_ZN15MainWindowAdminE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindowAdmin",
        "on_AddUserButton_clicked",
        "",
        "on_PenalizeUserButton_clicked",
        "on_DeleteUserButton_clicked",
        "on_EditUserButton_clicked",
        "on_ListOfBannedUsersButton_clicked",
        "on_ListOfPenalizedUsersButton_clicked",
        "on_AddBookButton_clicked",
        "on_DeleteBookButton_clicked",
        "on_EditBookButton_clicked",
        "on_ListOfBorrowedBooksButton_clicked",
        "on_dashboardButton_clicked",
        "on_dashboardButton_3_clicked",
        "on_dashboardButton_2_clicked",
        "on_dashboardButton_4_clicked",
        "on_dashboardButton_5_clicked",
        "on_ListOfUnreturnedBooksButton_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_AddUserButton_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_PenalizeUserButton_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_DeleteUserButton_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_EditUserButton_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ListOfBannedUsersButton_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ListOfPenalizedUsersButton_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_AddBookButton_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_DeleteBookButton_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_EditBookButton_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ListOfBorrowedBooksButton_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_dashboardButton_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_dashboardButton_3_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_dashboardButton_2_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_dashboardButton_4_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_dashboardButton_5_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ListOfUnreturnedBooksButton_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindowAdmin, qt_meta_tag_ZN15MainWindowAdminE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindowAdmin::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MainWindowAdminE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MainWindowAdminE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15MainWindowAdminE_t>.metaTypes,
    nullptr
} };

void MainWindowAdmin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindowAdmin *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_AddUserButton_clicked(); break;
        case 1: _t->on_PenalizeUserButton_clicked(); break;
        case 2: _t->on_DeleteUserButton_clicked(); break;
        case 3: _t->on_EditUserButton_clicked(); break;
        case 4: _t->on_ListOfBannedUsersButton_clicked(); break;
        case 5: _t->on_ListOfPenalizedUsersButton_clicked(); break;
        case 6: _t->on_AddBookButton_clicked(); break;
        case 7: _t->on_DeleteBookButton_clicked(); break;
        case 8: _t->on_EditBookButton_clicked(); break;
        case 9: _t->on_ListOfBorrowedBooksButton_clicked(); break;
        case 10: _t->on_dashboardButton_clicked(); break;
        case 11: _t->on_dashboardButton_3_clicked(); break;
        case 12: _t->on_dashboardButton_2_clicked(); break;
        case 13: _t->on_dashboardButton_4_clicked(); break;
        case 14: _t->on_dashboardButton_5_clicked(); break;
        case 15: _t->on_ListOfUnreturnedBooksButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindowAdmin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowAdmin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MainWindowAdminE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowAdmin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
