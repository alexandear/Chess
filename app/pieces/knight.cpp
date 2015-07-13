#include "knight.h"
#include "board.h"

Knight::Knight(Game::Side t_side)
    : AbstractPiece(t_side)
{
}

bool Knight::areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                                 const Board& t_board) const
{
    Q_UNUSED(t_board)
    // Destination square is unoccupied or occupied by opposite color
    if (check(t_from, t_to, 1, 2) || check(t_from, t_to, 2, 1))
        return true;
    return false;
}

bool Knight::check(const Coordinate& t_from, const Coordinate& t_to,
                   int t_left, int t_right) const
{
    if (((t_from.file() == t_to.file() + t_left)
         || (t_from.file() == t_to.file() - t_left))
            && ((t_from.rank() == t_to.rank() + t_right)
                || (t_from.rank() == t_to.rank() - t_right)))
        return true;
    return false;
}

