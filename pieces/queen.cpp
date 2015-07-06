#include "queen.h"

Queen::Queen(Game::Side t_side)
    : AbstractPiece(t_side), Bishop(t_side), Rook(t_side)
{

}

bool Queen::areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                            const Board& t_board) const
{
    return Bishop::areSquaresPermitted(t_from, t_to, t_board)
            || Rook::areSquaresPermitted(t_from, t_to, t_board);
}

