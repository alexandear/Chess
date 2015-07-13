#include <tuple>

#include <QString>
#include <QtTest>

#include "../app/fenparser.h"
#include "../app/board.h"

class FenParserTest : public QObject
{
    Q_OBJECT

public:
    FenParserTest();

private Q_SLOTS:
    void readInitialTestCase();

};

FenParserTest::FenParserTest()
{
}

void FenParserTest::readInitialTestCase()
{
    auto tuple = FenParser().read(
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    auto moveNumber = 0;
    auto activeSide = Game::Side::Black;
    auto pieces = Board::PiecesMatrix{};
    std::tie(pieces, activeSide, moveNumber) = tuple;
    QVERIFY(activeSide == Game::Side::White && moveNumber == 1);
}

QTEST_APPLESS_MAIN(FenParserTest)

#include "tst_fenparsertest.moc"

//    game.nextMove({ 1, 0 }, { 2, 0 });
//    game.nextMove({ 7, 1 }, { 5, 2});

//    try {
//        Board board;
//        board.print();
//        board.setFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
//        board.print();
//        board.setFen("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
//        board.print();
//        board.setFen("4k3/8/8/8/8/8/4P3/4K3 w - - 5 39");
//        board.print();
//    } catch (FenParserError& e) {
//        QMessageBox msg;
//        msg.setIcon(QMessageBox::Critical);
//        msg.setText(e.what());
//        msg.exec();
//    } catch (...) {
//    }
