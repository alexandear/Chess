#pragma once

#include <QString>
#include <memory>

#include "side.h"

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

    explicit AbstractPiece(Side t_side);
    virtual ~AbstractPiece() {}
    AbstractPiece(const AbstractPiece&) = default;
    AbstractPiece(AbstractPiece&&) = default;
    AbstractPiece& operator=(const AbstractPiece&) & = default;
    AbstractPiece& operator=(AbstractPiece&&) & = default;

    static QString toString(Type t_type);

    static PiecePtr make(Type t_type, Side t_side);

    bool isMovePermitted(const Coordinate& t_from, const Coordinate& t_to,
                         const Board& t_board) const;

    virtual Type type() const = 0;
    Side side() const { return m_side; }
    operator QString() { return ::toString(side()) + " " + toString(type()); }

protected:
    virtual bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                                 const Board& t_board) const = 0;

    Side m_side;

};

