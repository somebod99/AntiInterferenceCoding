QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GilberMoorParityCheck.cpp \
    HammingAlgorithm.cpp \
    Tools.cpp \
    decodewidget.cpp \
    encodewidget.cpp \
    hammingdecodewidget.cpp \
    hammingencodewidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GilberMoorParityCheck.h \
    HammingAlgorithm.h \
    Tools.h \
    decodewidget.h \
    encodewidget.h \
    hammingdecodewidget.h \
    hammingencodewidget.h \
    mainwindow.h

FORMS += \
    decodewidget.ui \
    encodewidget.ui \
    hammingdecodewidget.ui \
    hammingencodewidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
