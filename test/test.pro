TEMPLATE = app

CONFIG   += console C++11
CONFIG   -= app_bundle

INCLUDEPATH += ../app/

SOURCES += main.cpp \
    ../app/gamecontroller.cpp \
    ../app/pieces/abstractpiece.cpp \
    ../app/board.cpp \
    ../app/pieces/pawn.cpp \
    ../app/pieces/knight.cpp \
    ../app/pieces/bishop.cpp \
    ../app/pieces/rook.cpp \
    ../app/pieces/queen.cpp \
    ../app/pieces/king.cpp \
    ../app/fenparser.cpp \
    ../app/game.cpp

HEADERS += \
    ../app/gamecontroller.h \
    ../app/pieces/abstractpiece.h \
    ../app/board.h \
    ../app/pieces/pawn.h \
    ../app/coordinate.h \
    ../app/pieces/knight.h \
    ../app/pieces/bishop.h \
    ../app/pieces/rook.h \
    ../app/pieces/queen.h \
    ../app/pieces/king.h \
    ../app/fenparser.h \
    ../app/game.h
