#pragma once

#include "abstractpiece.h"

class Rook : virtual public AbstractPiece
{
public:
    Rook(Game::Side t_side);

    AbstractPiece::Type type() const override { return AbstractPiece::Type::Rook; }

protected:
    bool areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                         const Board& t_board) const override;

    bool check(const Coordinate& t_from, const Coordinate& t_to,
               const Board& t_board, bool t_rank) const;
};


