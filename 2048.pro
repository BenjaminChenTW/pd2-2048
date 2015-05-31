#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T15:26:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainpage.cpp \
    enterpage.cpp \
    game.cpp

HEADERS  += mainpage.h \
    enterpage.h \
    game.h

FORMS    += mainpage.ui \
    enterpage.ui

RESOURCES += \
    images.qrc
