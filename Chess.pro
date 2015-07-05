TEMPLATE = app

QT += widgets

SOURCES += main.cpp \
    gamecontroller.cpp \
    abstractpiece.cpp \
    board.cpp \
    pawn.cpp \
    knight.cpp \
    bishop.cpp \
    rook.cpp \
    queen.cpp \
    king.cpp \
    side.cpp \
    fenparser.cpp

CONFIG += C++11 console

HEADERS += \
    gamecontroller.h \
    abstractpiece.h \
    board.h \
    pawn.h \
    coordinate.h \
    knight.h \
    bishop.h \
    rook.h \
    queen.h \
    king.h \
    side.h \
    fenparser.h
