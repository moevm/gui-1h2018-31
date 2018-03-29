#-------------------------------------------------
#
# Project created by QtCreator 2018-03-14T00:26:44
#
#-------------------------------------------------
QT       += core gui multimedia

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Player
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
        main.cpp \
        widget.cpp \
    style.cpp

HEADERS += \
        widget.h \
    style.h

FORMS += \
        widget.ui

RESOURCES += \
    resourses.qrc
