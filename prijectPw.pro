QT       += core gui sql xlsx  printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appcenter.cpp \
    choiceprofessor.cpp \
    dbhelper.cpp \
    filehelper.cpp \
    judges.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    professor.cpp \
    professormanagement.cpp \
    professormodel.cpp \
    unsercenter.cpp

HEADERS += \
    appcenter.h \
    choiceprofessor.h \
    dbhelper.h \
    filehelper.h \
    judges.h \
    login.h \
    mainwindow.h \
    professor.h \
    professormanagement.h \
    professormodel.h \
    unsercenter.h

FORMS += \
    choiceprofessor.ui \
    judges.ui \
    login.ui \
    mainwindow.ui \
    professormanagement.ui \
    unsercenter.ui

TRANSLATIONS += \
    prijectPw_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR += $$PWD/./bin

RESOURCES += \
    icon.qrc

TARGET=Management
