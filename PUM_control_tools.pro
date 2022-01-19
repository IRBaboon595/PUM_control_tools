QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# CONFIG += qwt


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractamplifier.cpp \
    hardwaredevice.cpp \
    main.cpp \
    mainwindow.cpp \
    powamp.cpp \
    preamp.cpp

HEADERS += \
    abstractamplifier.h \
    hardwaredevice.h \
    mainwindow.h \
    powamp.h \
    preamp.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# win32:CONFIG(release, debug|release): LIBS += -LC:/qwt-6.1.6/QWT_LIB/lib/ -lqwt
# else:win32:CONFIG(debug, debug|release): LIBS += -LC:/qwt-6.1.6/QWT_LIB/lib/ -lqwtd
# else:unix: LIBS += -L$$PWD/../../../qwt-6.1.6/QWT_LIB/lib/ -lqwt

# INCLUDEPATH += C:/qwt-6.1.6/QWT_LIB/include
# DEPENDPATH += C:/qwt-6.1.6/QWT_LIB/include
