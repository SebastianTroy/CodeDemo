QT += core
QT -= gui

CONFIG += c++11

TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Node.cpp \
    TravellingSalesmanSolutionHillclimber.cpp \
    Journey.cpp

HEADERS += \
    Node.h \
    TravellingSalesmanSolutionHillclimber.h \
    Journey.h
