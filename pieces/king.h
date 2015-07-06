#pragma once

#include "abstractpiece.h"

class King : public AbstractPiece
{
public:
    King(Game::Side t_side);

    AbstractPiece::Type type() const override { return AbstractPiece::Type::King; }

protected:
    bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                         const Board& t_board) const override;
};

