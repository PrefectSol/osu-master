QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = osu-master

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apphandler.cpp \
    cursorhandler.cpp \
    datahandler.cpp \
    difficultysection.cpp \
    editorsection.cpp \
    generalsection.cpp \
    main.cpp \
    mainwindow.cpp \
    metadatasection.cpp \
    osudecoder.cpp \
    osurequest.cpp \
    section.cpp \
    utilities.cpp

HEADERS += \
    HitObject.h \
    TimingPoint.h \
    apphandler.h \
    cursorhandler.h \
    datahandler.h \
    difficultysection.h \
    editorsection.h \
    generalsection.h \
    mainwindow.h \
    metadatasection.h \
    osudecoder.h \
    osurequest.h \
    section.h \
    settings.hpp \
    ui.h \
    utilities.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc

DISTFILES +=
