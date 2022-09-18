QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calc.c \
    create_stack_digit.c \
    create_stack_sign.c \
    graphic.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    support_func.c \
    validation.c

HEADERS += \
    mainwindow.h \
    qcustomplot.h \
    s21_calc.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
