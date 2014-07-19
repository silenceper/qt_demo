#-------------------------------------------------
#
# Project created by QtCreator 2014-05-24T16:19:30
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MD5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    encrypt.cpp \
    decrypt.cpp

HEADERS  += mainwindow.h \
    encrypt.h \
    decrypt.h

RESOURCES += \
    res.qrc
RC_ICONS = images/icon-md5.ico
VERSION=0.1
