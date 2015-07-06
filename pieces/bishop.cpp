#include "bishop.h"
#include "board.h"

Bishop::Bishop(Game::Side t_side)
    : AbstractPiece(t_side)
{
}

bool Bishop::areSquaresPermitted(const Coordinate& t_from, const Coordinate& t_to,
                             const Board& t_board) const
{
    if ((t_to.file() - t_from.file() == t_to.rank() - t_from.rank())
        || (t_to.file() - t_from.file() == t_from.rank() - t_to.rank())) {
        // Make sure that all invervening squares are empty
        auto rankOffset = (t_to.rank() - t_from.rank() > 0) ? 1 : -1;
        auto fileOffset = (t_to.file() - t_from.file() > 0) ? 1 : -1;

        auto checkRank = 0, checkFile = 0;
        for (checkRank = t_from.rank() + rankOffset, checkFile = t_from.file() + fileOffset;
             checkRank != t_to.rank();
             checkRank += rankOffset, checkFile += fileOffset)
        {
            if (t_board.at({checkRank, checkFile}))
                return false;
        }
        return true;
    }
    return false;
}

