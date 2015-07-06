#include <QApplication>
#include <QDebug>

#include "gamecontroller.h"
#include "fenparser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameController game;
    game.nextMove({ 1, 0 }, { 2, 0 });
    game.nextMove({ 7, 1 }, { 5, 2});

    FenParser fen;
    try {
        auto boardStart = fen.read("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        boardStart.print();

        auto boardMiddle = fen.read("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
        boardMiddle.print();

        auto boardEnd = fen.read("4k3/8/8/8/8/8/4P3/4K3 w - - 5 39");
        boardEnd.print();
    } catch (std::exception& e) {
        qDebug() << e.what();
    }

    return app.exec();
}
