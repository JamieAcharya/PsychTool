QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algorithms/Algorithm2/algorithm_2.cpp \
    Algorithms/Algorithm3/algorithm_3.cpp \
    Functions/Random/random.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    psych.cpp

HEADERS += \
    Algorithms/Algorithm1/Algorithm_1.h \
    Algorithms/Algorithm2/algorithm_2.h \
    Algorithms/Algorithm3/algorithm_3.h \
    Functions/Random/random.h \
    mainwindow.h \
    menu.h \
    psych.h

FORMS += \
    mainwindow.ui \
    menu.ui

LIBS += opengl32.lib
#LIBS += glu32.lib
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Algorithms/Algorithm2/Algorithm_2.frag \
    Algorithms/Algorithm2/Algorithm_2.vert \
    Algorithms/Algorithm3/Algorithm_3.frag \
    Algorithms/Algorithm3/Algorithm_3.vert \
