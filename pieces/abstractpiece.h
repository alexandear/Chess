#pragma once

#include <QString>
#include <memory>

#include "game.h"

class Board;
class Coordinate;

class AbstractPiece
{
public:
    using PiecePtr = std::shared_ptr<AbstractPiece>;

    enum class Type
    {
        Empty,
        Pawn,
        Knight,
        Bishop,
        Rook,
        Queen,
        King
    };

    explicit AbstractPiece(Game::Side t_side);
    virtual ~AbstractPiece() {}
    AbstractPiece(const AbstractPiece&) = default;
    AbstractPiece(AbstractPiece&&) = default;
    AbstractPiece& operator=(const AbstractPiece&) & = default;
    AbstractPiece& operator=(AbstractPiece&&) & = default;

    static QString toString(Type t_type);
    static char letter(Type t_type);
    static Type fromLetter(char t_ch);

    static PiecePtr make(Type t_type, Game::Side t_side);

    bool isMovePermitted(const Coordinate& t_from, const Coordinate& t_to,
                         const Board& t_board) const;

    virtual Type type() const = 0;
    Game::Side side() const { return m_side; }
    operator QString() { return Game::toString(side()) + " " + toString(type()); }

protected:
    virtual bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                                 const Board& t_board) const = 0;

    Game::Side m_side;

};

