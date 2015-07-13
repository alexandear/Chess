#include "rook.h"
#include "board.h"

Rook::Rook(Game::Side t_side)
    : AbstractPiece(t_side)
{
}

bool Rook::areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                               const Board& t_board) const
{
    if (t_from.rank() == t_to.rank())
        return check(t_from, t_to, t_board, true);
    else if (t_from.file() == t_to.file())
        return check(t_from, t_to, t_board, false);

    return false;
}

bool Rook::check(const Coordinate& t_from, const Coordinate& t_to,
                 const Board& t_board, bool t_rank) const
{
    auto from = t_rank ? t_from.file() : t_from.rank();
    auto to = t_rank ? t_to.file() : t_to.file();

    // Make sure that all invervening squares are empty
    auto offset = (to - from > 0) ? 1 : -1;
    for (auto checkVal = from + offset; checkVal != to; checkVal += offset) {
        auto left = t_rank ? t_from.rank() : checkVal;
        auto right = t_rank ? checkVal : t_from.file();
        if (t_board.at({ left, right }))
            return false;
    }
    return true;
}

