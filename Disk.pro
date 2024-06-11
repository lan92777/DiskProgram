#-------------------------------------------------
#
# Project created by QtCreator 2024-06-02T09:58:33
#
#-------------------------------------------------

QT       += core gui
#…Ë÷√c++∞Ê±æ
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Disk
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    login.cpp \
    window_components/dashboard.cpp \
    window_components/myfile.cpp \
    window_components/sharelist.cpp \
    window_components/downlist.cpp \
    window_components/trans.cpp \
    common/des.c \
    common/logintitle.cpp

HEADERS  += mainwindow.h \
    login.h \
    window_components/dashboard.h \
    window_components/myfile.h \
    window_components/sharelist.h \
    window_components/downlist.h \
    window_components/trans.h \
    common/des.h \
    common/logintitle.h

FORMS    += mainwindow.ui \
    login.ui \
    window_components/dashboard.ui \
    window_components/myfile.ui \
    window_components/sharelist.ui \
    window_components/downlist.ui \
    window_components/trans.ui \
    common/logintitle.ui

RESOURCES += \
    res.qrc
