QT += core
QT -= gui
QT += dbus

CONFIG += c++11

TARGET = test-dbus
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mydbusadaptor.cpp

HEADERS += \
    mydbusadaptor.h
