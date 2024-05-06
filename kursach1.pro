QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonent.cpp \
    admin.cpp \
    adminz16.cpp \
    adminzayavki15.cpp \
    buh18.cpp \
    buhinst21.cpp \
    buhr20.cpp \
    buhz19.cpp \
    formaregistracii.cpp \
    istoria10.cpp \
    main.cpp \
    mainwindow.cpp \
    operator11.cpp \
    parol6.cpp \
    profile5.cpp \
    registrrab17.cpp \
    txtworker.cpp \
    uslovia8.cpp \
    uslugi9.cpp \
    usluginachalo.cpp \
    uslugiris7.cpp \
    zayavki12.cpp \
    zayavki13.cpp

HEADERS += \
    abonent.h \
    admin.h \
    adminz16.h \
    adminzayavki15.h \
    buh18.h \
    buhinst21.h \
    buhr20.h \
    buhz19.h \
    formaregistracii.h \
    istoria10.h \
    mainwindow.h \
    operator11.h \
    parol6.h \
    profile5.h \
    registrrab17.h \
    txtworker.h \
    uslovia8.h \
    uslugi9.h \
    usluginachalo.h \
    uslugiris7.h \
    zayavki12.h \
    zayavki13.h

FORMS += \
    abonent.ui \
    admin.ui \
    adminz16.ui \
    adminzayavki15.ui \
    buh18.ui \
    buhinst21.ui \
    buhr20.ui \
    buhz19.ui \
    formaregistracii.ui \
    istoria10.ui \
    mainwindow.ui \
    operator11.ui \
    parol6.ui \
    profile5.ui \
    registrrab17.ui \
    uslovia8.ui \
    uslugi9.ui \
    usluginachalo.ui \
    uslugiris7.ui \
    zayavki12.ui \
    zayavki13.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
