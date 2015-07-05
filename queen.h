#pragma once

#include "bishop.h"
#include "rook.h"

class Queen : public Bishop, public Rook
{
public:
    Queen(Side t_side);

    AbstractPiece::Type type() const override { return AbstractPiece::Type::Queen; }

private:
    bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                         const Board& t_board) const override;
};

