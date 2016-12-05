QT  += network widgets
QT  += core


CONFIG += c++11

TARGET = UdpMulticastReceiver
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    receiver.cpp \
    packageFormat.pb.cc

HEADERS += \
    receiver.h \
    packageFormat.pb.h \
    pbuff.h


INCLUDEPATH += $$PWD/../../../../../../Games/protobuf1/src

win32: LIBS += -L$$PWD/../UpdMulticastSender/ -lprotobuf

INCLUDEPATH += $$PWD/../UpdMulticastSender
DEPENDPATH += $$PWD/../UpdMulticastSender

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../UpdMulticastSender/protobuf.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../UpdMulticastSender/libprotobuf.a

