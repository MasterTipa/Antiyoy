QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BlueTeam.cpp \
    CreateWorriarB.cpp \
    CreateWorriarR.cpp \
    Game.cpp \
    GameOver.cpp \
    RandomMap.cpp \
    RedPerson.cpp \
    RedTeam.cpp \
    ScoreB.cpp \
    ScoreR.cpp \
    ScoreToWin.cpp \
    WinTextB.cpp \
    WinTextR.cpp \
    main.cpp

HEADERS += \
    BlueTeam.h \
    CreateWorriarB.h \
    CreateWorriarR.h \
    Game.h \
    GameOver.h \
    RandomMap.h \
    RedPerson.h \
    RedTeam.h \
    ScoreB.h \
    ScoreR.h \
    ScoreToWin.h \
    WinTextB.h \
    WinTextR.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    textur.qrc

DISTFILES += \
    Blue.png \
    BluePerson.png \
    GameOver.jpg \
    Red.png \
    RedPerson.png \
    background.jpg \
    sand.jpg
