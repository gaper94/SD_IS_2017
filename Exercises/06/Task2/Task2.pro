QT += core
QT -= gui

TARGET = Task2
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    String.cpp

HEADERS += \
    Stack.hpp \
    Stack.h \
    Node.h \
    ListIterator.hpp \
    ListIterator.h \
    LinkedList.hpp \
    LinkedList.h \
    String.h

