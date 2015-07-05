#pragma once

#include "abstractpiece.h"

class Bishop : virtual public AbstractPiece
{
public:
    Bishop(Side t_side);

    AbstractPiece::Type type() const override { return AbstractPiece::Type::Bishop; }

protected:
    bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                             const Board& t_board) const override;
};

