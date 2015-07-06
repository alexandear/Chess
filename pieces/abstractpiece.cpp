#include <QPoint>

#include "abstractpiece.h"
#include "board.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
#include "queen.h"

AbstractPiece::AbstractPiece(Game::Side t_side)
    : m_side(t_side)
{
}

bool AbstractPiece::isMovePermitted(const Coordinate& t_from, const Coordinate& t_to,
                                const Board& t_board) const
{
    auto dest = t_board.at(t_to);
    if (!dest || m_side != dest->side())
        return areSquaresPermitted(t_from, t_to, t_board);
    return false;
}

QString AbstractPiece::toString(Type t_type)
{
    switch (t_type) {
    case Type::Pawn:
        return "Pawn";
    case Type::Knight:
        return "Knight";
    case Type::Bishop:
        return "Bishop";
    case Type::Rook:
        return "Rook";
    case Type::Queen:
        return "Queen";
    case Type::King:
        return "King";
    default:
        return " ";
    }
}

char AbstractPiece::letter(AbstractPiece::Type t_type)
{
    switch (t_type) {
    case Type::Pawn:
        return 'p';
    case Type::Knight:
        return 'n';
    case Type::Bishop:
        return 'b';
    case Type::Rook:
        return 'r';
    case Type::Queen:
        return 'q';
    case Type::King:
        return 'k';
    default:
        return ' ';
    }
}

AbstractPiece::Type AbstractPiece::fromLetter(char t_ch)
{
    switch (tolower(t_ch)) {
    case 'p':
        return Type::Pawn;
    case 'n':
        return Type::Knight;
    case 'b':
        return Type::Bishop;
    case 'r':
        return Type::Rook;
    case 'q':
        return Type::Queen;
    case 'k':
        return Type::King;
    default:
        return Type::Empty;
    }
}

AbstractPiece::PiecePtr AbstractPiece::make(Type t_type, Game::Side t_side)
{
    using std::make_shared;
    switch (t_type) {
    case Type::Pawn:
        return make_shared<Pawn>(t_side);
    case Type::Knight:
        return make_shared<Knight>(t_side);
    case Type::Bishop:
        return make_shared<Bishop>(t_side);
    case Type::Rook:
        return make_shared<Rook>(t_side);
    case Type::Queen:
        return make_shared<Queen>(t_side);
    case Type::King:
        return make_shared<King>(t_side);
    default:
        return make_shared<Pawn>(t_side);
    }
}

