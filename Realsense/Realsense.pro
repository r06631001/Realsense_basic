#-------------------------------------------------
#
# Project created by QtCreator 2018-08-14T16:04:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Realsense
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += link_pkgconfig

INCLUDEPATH += C:/intel_realsense_SDK2.0_2.10.4_modify/include

HEADERS += C:/intel_realsense_SDK2.0_2.10.4_modify/src/
LIBS += C:/intel_realsense_SDK2.0_2.10.4_modify/lib/realsense2.lib

INCLUDEPATH += C:\\opencv3.2.0_x64_vc2015\\include \
                C:\\opencv3.2.0_x64_vc2015\\include\\opencv \
                C:\\opencv3.2.0_x64_vc2015\\include\\opencv2 \

LIBS +=  C:\\opencv3.2.0_x64_vc2015\\lib\\opencv_world320.lib \
         C:\\opencv3.2.0_x64_vc2015\\lib\\opencv_world320d.lib \

SOURCES += \
        main.cpp \
        realsense.cpp

HEADERS += \
        realsense.hpp

FORMS += \
        realsense.ui
