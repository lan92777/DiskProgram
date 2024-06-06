#-------------------------------------------------
#
# Project created by QtCreator 2024-06-02T09:58:33
#
#-------------------------------------------------

QT       += core gui
#设置c++编译器版本
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Disk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    common/logintitle.cpp

HEADERS  += mainwindow.h \
    login.h \
    common/logintitle.h

FORMS    += mainwindow.ui \
    login.ui \
    common/logintitle.ui

RESOURCES += \
    res.qrc
