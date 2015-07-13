#include <QTextStream>

#include "pieces/abstractpiece.h"
#include "board.h"
#include "fenparser.h"

const QString Board::START_FEN =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

void Board::setFen(const QString& t_fenStr)
{
    auto fenTuple = FenParser().read(t_fenStr);
    std::tie(m_pieces, m_activeSide, m_moveNumber) = fenTuple;
}

void Board::move(const Coordinate& t_from, const Coordinate& t_to)
{
    auto currPiece = at(t_from);
    if (currPiece) {
        if (currPiece->isMovePermitted(t_from, t_to, *this)) {
            at(t_to) = currPiece;
            at(t_from).reset();
        }
    }
}

QString Board::piecesToString() const
{
    QString res;
    res.reserve(BOARD_SIZE * BOARD_SIZE);
    for (auto i = 0; i < BOARD_SIZE; ++i) {
        for (auto j = 0; j < BOARD_SIZE; ++j) {
            res.push_front(at(i, j) ? at(i, j)->letter() : ' ');
        }
    }
    return res;
}

void Board::print() const
{
    QTextStream sout(stdout);

    const int kiSquareWidth = 4;
    const int kiSquareHeight = 3;
    for (int iRow = 0; iRow < 8*kiSquareHeight; ++iRow) {
        int iSquareRow = iRow/kiSquareHeight;
        // Print side border with numbering
        if (iRow % 3 == 1) {
            sout << '-' << (char)('1' + 7 - iSquareRow) << '-';
        } else {
            sout << "---";
        }
        // Print the chess board
        for (int iCol = 0; iCol < 8*kiSquareWidth; ++iCol) {
            int iSquareCol = iCol/kiSquareWidth;
            if (((iRow % 3) == 1) && ((iCol % 4) == 1 || (iCol % 4) == 2)
                    && at(7-iSquareRow, iSquareCol)) {
                if ((iCol % 4) == 1) {
                    sout << Game::letter(at(7-iSquareRow, iSquareCol)->side());
                } else {
                    sout << AbstractPiece::letter(at(7-iSquareRow, iSquareCol)->type());
                }
            } else {
                if ((iSquareRow + iSquareCol) % 2 == 1) {
                    sout << '*';
                } else {
                    sout << ' ';
                }
            }
        }
        sout << endl;
    }
    // Print the bottom border with numbers
    for (int iRow = 0; iRow < kiSquareHeight; ++iRow) {
        if (iRow % 3 == 1) {
            sout << "---";
            for (int iCol = 0; iCol < 8*kiSquareWidth; ++iCol) {
                int iSquareCol = iCol/kiSquareWidth;
                if ((iCol % 4) == 1) {
                    sout << (iSquareCol + 1);
                } else {
                    sout << '-';
                }
            }
            sout << endl;
        } else {
            for (int iCol = 1; iCol < 9*kiSquareWidth; ++iCol) {
                sout << '-';
            }
            sout << endl;
        }
    }

}

