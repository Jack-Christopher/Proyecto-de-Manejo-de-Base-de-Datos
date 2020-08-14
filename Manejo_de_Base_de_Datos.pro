QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Configura el standard del lenguaje
CONFIG += c++17

INCLUDEPATH += $$PWD

DEFINES += QT_DEPRECATED_WARNINGS

#Archivos .cpp
SOURCES += \
    administrador.cpp \
    controlproductosform.cpp \
    controlvendedoresform.cpp \
    database.cpp \
    databasefunctions.cpp \
    dialog.cpp \
    facade.cpp \
    main.cpp \
    mainwindow.cpp \
    modificarproductodialog.cpp \
    producto.cpp \
    registrarproductodialog.cpp \
    registrarvendedordialog.cpp \
    vendedor.cpp

#Archivos .h (headers)
HEADERS += \
    administrador.h \
    controlproductosform.h \
    controlvendedoresform.h \
    database.h \
    databasefunctions.h \
    dialog.h \
    facade.h \
    mainwindow.h \
    modificarproductodialog.h \
    producto.h \
    registrarproductodialog.h \
    registrarvendedordialog.h \
    vendedor.h

#Archivos .ui (interfaces graficas)
FORMS += \
    controlproductosform.ui \
    controlvendedoresform.ui \
    dialog.ui \
    mainwindow.ui \
    modificarproductodialog.ui \
    registrarproductodialog.ui \
    registrarvendedordialog.ui

RC_ICONS = tienda.ico

# Reglas por defecto para el deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
