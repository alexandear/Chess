TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    gamecontroller.cpp \
    pieces/abstractpiece.cpp \
    board.cpp \
    pieces/pawn.cpp \
    pieces/knight.cpp \
    pieces/bishop.cpp \
    pieces/rook.cpp \
    pieces/queen.cpp \
    pieces/king.cpp \
    fenparser.cpp \
    game.cpp

RESOURCES += resources.qrc

CONFIG += C++11 console

HEADERS += \
    gamecontroller.h \
    pieces/abstractpiece.h \
    board.h \
    pieces/pawn.h \
    coordinate.h \
    pieces/knight.h \
    pieces/bishop.h \
    pieces/rook.h \
    pieces/queen.h \
    pieces/king.h \
    fenparser.h \
    game.h

OTHER_FILES = qml/Constants.js \
    qml/main.qml \
    qml/ChessBoard.qml \
    qml/GameButton.qml