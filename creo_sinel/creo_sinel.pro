#-------------------------------------------------
#
# Project created by QtCreator 2017-01-24T09:53:38
#
#-------------------------------------------------

QT       += core gui sql widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = creo_sinel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    add_to_db.cpp

HEADERS  += mainwindow.h \
    add_to_db.h

FORMS    += mainwindow.ui \
    add_to_db.ui
