#include "king.h"
#include "board.h"

King::King(Game::Side t_side)
    : AbstractPiece(t_side)
{
}

bool King::areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                           const Board& t_board) const
{
    Q_UNUSED(t_board)

    auto rankDelta = t_to.rank() - t_from.rank();
    auto fileDelta = t_to.file() - t_from.file();

    if (rankDelta >= -1 && rankDelta <= 1 && fileDelta >= -1 && fileDelta <= 1)
        return true;
    return false;
}

