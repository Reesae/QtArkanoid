#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T10:55:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtArkanoid
TEMPLATE = app
CONFIG += c++14

SOURCES += main.cpp \
    game.cpp \
    block.cpp \
    player.cpp \
    ball.cpp \
    level.cpp

HEADERS  += \
    game.h \
    block.h \
    player.h \
    ball.h \
    level.h \
    settings.h

FORMS    +=

RESOURCES += \
    images.qrc
