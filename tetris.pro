#-------------------------------------------------
#
# Project created by QtCreator 2016-01-15T15:09:05
#
#-------------------------------------------------


QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connexion.cpp

HEADERS  += mainwindow.h \
    connexion.h

FORMS    += mainwindow.ui
