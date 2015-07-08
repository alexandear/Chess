#include <QApplication>
#include <QDebug>
#include <QMessageBox>

#include "gamecontroller.h"
#include "fenparser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameController game;
    game.nextMove({ 1, 0 }, { 2, 0 });
    game.nextMove({ 7, 1 }, { 5, 2});

    try {
        Board board;
        board.print();
        board.setFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        board.print();
        board.setFen("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
        board.print();
        board.setFen("4k3/8/8/8/8/8/4P3/4K3 w - - 5 39");
        board.print();
    } catch (FenParserError& e) {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText(e.what());
        msg.exec();
    } catch (...) {
    }

    return app.exec();
}
