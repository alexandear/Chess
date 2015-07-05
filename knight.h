#pragma once

#include "abstractpiece.h"

class Knight : public AbstractPiece
{
public:
    Knight(Side t_side);

    AbstractPiece::Type type() const override { return AbstractPiece::Type::Knight; }

private:
    bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                         const Board& t_board) const override;

    bool check(const Coordinate& t_from, const Coordinate& t_to, int t_left, int t_right) const;
};
