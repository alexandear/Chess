#include "pawn.h"
#include "board.h"

Pawn::Pawn(Game::Side t_side)
    : AbstractPiece(t_side)
{
}

bool Pawn::areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                           const Board& t_board) const
{
    const auto& dest = t_board.at(t_to);
    if (!dest) {
        // Destination square is unoccupied
        if (t_from.file() == t_to.file())
            if (check(t_from, t_to))
                return true;
    } else {
        // Destination hold piece of opposite side
        if((t_from.file() == t_to.file() + 1) || (t_from.file() == t_to.file() - 1))
            if (check(t_from, t_to))
                return true;
    }
    return false;
}

bool Pawn::check(const Coordinate& t_from, const Coordinate& t_to) const
{
    if (side() == Game::Side::White) {
        if (t_to.rank() == t_from.rank() + 1)
            return true;
    } else {
        if (t_to.rank() == t_from.rank() - 1)
            return true;
    }
    return false;
}

