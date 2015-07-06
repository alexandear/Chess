#include <stdexcept>
#include <QDebug>

#include "pieces/abstractpiece.h"
#include "fenparser.h"


Board FenParser::read(const QString& t_fenRow) const
{
    Board board;

    auto splitted = t_fenRow.split(" ");

    auto pieces = parsePiecePlacement(splitted[0]);
    auto activeSide = parseActiveSide(splitted[1]);
    auto fullmoveNumber = parseFullmoveNumber(splitted[5]);

    board.setPieces(pieces);
    board.setActiveSide(activeSide);
    board.setMoveNumber(fullmoveNumber);

    return board;
}

Board::PiecesMatrix FenParser::parsePiecePlacement(const QString& t_piecePlacement) const
{
    for (auto ch : t_piecePlacement) {
        if (!isSymbolPermitted(ch.toLatin1()) && ch != SEP)
            throw std::runtime_error("Invalid symbols in piece placement");
    }

    auto ranks = t_piecePlacement.split(SEP);

    Board::PiecesMatrix piecesMatrix;

    auto j = 0;
    for (auto rank : ranks) {
        auto i = 0;
        for (auto cell : rank) {
            auto ch = cell.toLatin1();
            if (isdigit(ch)) {
                i += QString(ch).toInt();
                continue;
            }
            auto side = isupper(ch) ? Game::Side::White : Game::Side::Black;
            piecesMatrix.at(i).at(j) = AbstractPiece::make(AbstractPiece::fromLetter(ch), side);
            ++i;
        }
        ++j;
    }

    return piecesMatrix;
}

Game::Side FenParser::parseActiveSide(const QString& t_side) const
{
    auto side = t_side[0];
    auto black = Game::letter(Game::Side::Black);
    auto white = Game::letter(Game::Side::White);
    if (t_side.size() != 1 || (side != black && side != white))
        throw std::runtime_error("Invalid side symbol");
    return side == white ? Game::Side::White : Game::Side::Black;
}

int FenParser::parseFullmoveNumber(const QString& t_moveNumber) const
{
    auto ok = false;
    auto res = t_moveNumber.toInt(&ok);
    if (!ok || res < 1)
        throw std::runtime_error("Invalid fullmove number");
    return res;
}

bool FenParser::isSymbolPermitted(char t_ch) const
{
    AbstractPiece::Type pieces[] = {
        AbstractPiece::Type::Pawn, AbstractPiece::Type::Knight, AbstractPiece::Type::Bishop,
        AbstractPiece::Type::Rook, AbstractPiece::Type::Queen, AbstractPiece::Type::King
    };

    for (auto piece : pieces) {
        if (tolower(t_ch) == AbstractPiece::letter(piece))
            return true;
    }
    return isdigit(t_ch) && t_ch != '0';
}

