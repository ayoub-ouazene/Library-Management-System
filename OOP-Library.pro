QT   += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrator.cpp \
    article.cpp \
    book.cpp \
    bookdialog.cpp \
    content.cpp \
    databasemanager.cpp \
    databasemanagerbook.cpp \
    databasemanageruser.cpp \
    externel.cpp \
    librarian.cpp \
    library_director.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindowadmin.cpp \
    mainwindowuser.cpp \
    researchpaper.cpp \
    runtimefunctions.cpp \
    signinwindow.cpp \
    student.cpp \
    teacher.cpp \
    user.cpp \
    userdialog.cpp

HEADERS += \
    administrator.h \
    article.h \
    book.h \
    bookdialog.h \
    content.h \
    databasemanager.h \
    databasemanagerbook.h \
    databasemanageruser.h \
    externel.h \
    librarian.h \
    library_director.h \
    loginwindow.h \
    mainwindowadmin.h \
    mainwindowuser.h \
    researchpaper.h \
    runtimefunctions.h \
    signinwindow.h \
    student.h \
    teacher.h \
    user.h \
    userdialog.h

FORMS += \
    bookdialog.ui \
    loginwindow.ui \
    mainwindowadmin.ui \
    mainwindowuser.ui \
    signinwindow.ui \
    userdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    data.db
