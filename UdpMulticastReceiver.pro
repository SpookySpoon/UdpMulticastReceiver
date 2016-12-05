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

win32:INCLUDEPATH += "D:\Games\protobuf1\src"



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lprotobuf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lprotobufd

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./libprotobuf.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./libprotobuf.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./protobuf.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./protobuf.lib
