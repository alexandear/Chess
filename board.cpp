#include <QTextStream>

#include "pieces/abstractpiece.h"
#include "board.h"

Board::Board()
{
    placePieces(Game::Side::White);
    placePieces(Game::Side::Black);
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

void Board::placePieces(Game::Side t_side)
{
    using Type = AbstractPiece::Type;

    auto pawn = t_side == Game::Side::White ? 1 : 6;
    auto base = t_side == Game::Side::White ? 0 : 7;

    for (auto i = 0; i < SQUARE_COUNT; ++i)
        at(pawn, i) = AbstractPiece::make(Type::Pawn, t_side);
    at(base, 0) = AbstractPiece::make(Type::Rook,   t_side);
    at(base, 1) = AbstractPiece::make(Type::Knight, t_side);
    at(base, 2) = AbstractPiece::make(Type::Bishop, t_side);
    at(base, 3) = AbstractPiece::make(Type::King,   t_side);
    at(base, 4) = AbstractPiece::make(Type::Queen,  t_side);
    at(base, 5) = AbstractPiece::make(Type::Bishop, t_side);
    at(base, 6) = AbstractPiece::make(Type::Knight, t_side);
    at(base, 7) = AbstractPiece::make(Type::Rook,   t_side);
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

