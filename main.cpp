#include <QApplication>

#include "gamecontroller.h"
#include "fenparser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameController game;
    FenParser fen;
    fen.read("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
//    game.nextMove({ 1, 0 }, { 2, 0 });
//    game.nextMove({ 7, 1 }, { 5, 2});

    return app.exec();
}
