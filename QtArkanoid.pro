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

QMAKE_CXXFLAGS += -static-libgcc
QMAKE_CXXFLAGS += -static-libstdc++
QMAKE_CXXFLAGS += -ggdb
QMAKE_CXXFLAGS += -O

SOURCES += main.cpp \
    game.cpp \
    block.cpp \
    player.cpp \
    ball.cpp \
    level.cpp \
    lives.cpp \
    score.cpp \
    menubutton.cpp \
    utils.cpp \
    mainmenu.cpp \
    summaryscreen.cpp \
    powerup.cpp \
    playerpowerup.cpp \
    randomnumbergenerator.cpp

HEADERS  += \
    game.h \
    block.h \
    player.h \
    ball.h \
    level.h \
    settings.h \
    lives.h \
    score.h \
    menubutton.h \
    utils.h \
    mainmenu.h \
    summaryscreen.h \
    powerup.h \
    playerpowerup.h \
    randomnumbergenerator.h

FORMS    +=

RESOURCES += \
    images.qrc
