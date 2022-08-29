QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algorithm.cpp \
    lahore.cpp \
    main.cpp \
    mainwindow.cpp \
    pakistan.cpp \
    rawalpindi.cpp

HEADERS += \
    Algorithm.h \
    lahore.h \
    mainwindow.h \
    pakistan.h \
    rawalpindi.h

FORMS += \
    lahore.ui \
    mainwindow.ui \
    pakistan.ui \
    rawalpindi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Studies/4th Semester/Data Structures/Project/Background [2] [Clean].png \
    ../../Studies/4th Semester/Data Structures/Project/Background [2] [Clean].png
