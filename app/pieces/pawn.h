#pragma once

#include "abstractpiece.h"

class Pawn : public AbstractPiece
{
public:
    explicit Pawn(Game::Side t_side);

    AbstractPiece::Type type() const override { return AbstractPiece::Type::Pawn; }

private:
    bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                             const Board& t_board) const override;

    bool check(const Coordinate& t_from, const Coordinate& t_to) const;

};

