#pragma once

#include <map>

#include "board.h"

/*
 * Simplifien Forsyth–Edwards Notation
 *
 * Not implemented:
 * - castling ability
 * - en passant target square
 * - halfmove clock
 */
class FenParser
{
public:
    Board::PiecesMatrix read(const QString& t_row);

private:
};

