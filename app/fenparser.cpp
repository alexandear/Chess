#include <stdexcept>

#include "pieces/abstractpiece.h"
#include "fenparser.h"


std::tuple<Board::PiecesMatrix, Game::Side, int>
FenParser::read(const QString& t_fenRow) const
{
    auto splitted = t_fenRow.split(" ");

    auto pieces = parsePiecePlacement(splitted[0]);
    auto activeSide = parseActiveSide(splitted[1]);
    auto fullmoveNumber = parseFullmoveNumber(splitted[5]);

    return std::make_tuple(pieces, activeSide, fullmoveNumber);
}

Board::PiecesMatrix FenParser::parsePiecePlacement(const QString& t_piecePlacement) const
{
    for (auto ch : t_piecePlacement) {
        if (!isSymbolPermitted(ch.toLatin1()) && ch != SEP)
            throw FenParserError("Invalid symbols in piece placement");
    }

    auto ranks = reversed(t_piecePlacement.split(SEP));

    Board::PiecesMatrix piecesMatrix;

    auto j = 0;
    for (auto const& rank : ranks) {
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
        throw FenParserError("Invalid side symbol");
    return side == white ? Game::Side::White : Game::Side::Black;
}

int FenParser::parseFullmoveNumber(const QString& t_moveNumber) const
{
    auto ok = false;
    auto res = t_moveNumber.toInt(&ok);
    if (!ok || res < 1)
        throw FenParserError("Invalid fullmove number");
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


QStringList FenParser::reversed(const QStringList & t_list) const
{
    QStringList result;
    result.reserve(t_list.size());
    std::reverse_copy(t_list.begin(), t_list.end(), std::back_inserter(result));
    return result;
}

