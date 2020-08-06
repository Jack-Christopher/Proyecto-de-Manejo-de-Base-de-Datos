QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrador.cpp \
    controlproductosform.cpp \
    controlvendedoresform.cpp \
    database.cpp \
    databasefunctions.cpp \
    facade.cpp \
    main.cpp \
    login.cpp \
    mainwindow.cpp \
    modificarproductodialog.cpp \
    producto.cpp \
    registrarproductodialog.cpp \
    registrarvendedordialog.cpp \
    vendedor.cpp

HEADERS += \
    administrador.h \
    controlproductosform.h \
    controlvendedoresform.h \
    database.h \
    databasefunctions.h \
    facade.h \
    login.h \
    mainwindow.h \
    modificarproductodialog.h \
    producto.h \
    registrarproductodialog.h \
    registrarvendedordialog.h \
    vendedor.h

FORMS += \
    controlproductosform.ui \
    controlvendedoresform.ui \
    login.ui \
    mainwindow.ui \
    modificarproductodialog.ui \
    registrarproductodialog.ui \
    registrarvendedordialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
