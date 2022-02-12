TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Character.cpp \
        Command.cpp \
        CommandWords.cpp \
        Item.cpp \
        Parser.cpp \
        Room.cpp \
        Zork.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Item.h \
    Parser.h \
    Room.h \
    Zork.h
