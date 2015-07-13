TEMPLATE = app

QT += qml quick widgets

RESOURCES += resources.qrc

CONFIG += C++11 console

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

HEADERS += gamecontroller.h \
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

DISTFILES = qml/Constants.js \
    qml/Piece.qml \
    qml/MainWindow.qml \
    qml/Board.qml \
    qml/GameButton.qml

OTHER_FILES = qml/Constants.js
