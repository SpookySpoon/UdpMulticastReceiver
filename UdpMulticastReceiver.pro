QT  += network widgets
QT  += core


CONFIG += c++11

TARGET = UdpMulticastReceiver
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    receiver.cpp \
    receiverhub.cpp

HEADERS += \
    receiver.h \
    receiverhub.h
