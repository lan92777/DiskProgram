#-------------------------------------------------
#
# Project created by QtCreator 2024-06-02T09:58:33
#
#-------------------------------------------------

QT       += core gui
#设置c++编译器版�?
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Disk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    window_components/1.cpp \
    selfwindow/logintitle.cpp

HEADERS  += mainwindow.h \
    login.h \
    selfwindow/logintitle.h

FORMS    += mainwindow.ui \
    login.ui \
    selfwindow/logintitle.ui

RESOURCES += \
    res.qrc
