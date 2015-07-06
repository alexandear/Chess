#pragma once

#include "board.h"

/*
 * Simplified Forsyth–Edwards Notation
 *
 * Not implemented:
 * - castling ability
 * - en passant target square
 * - halfmove clock
 */
struct FenParser
{
    const char SEP = '/';

    Board read(const QString& t_fenRow) const;

private:
    Board::PiecesMatrix parsePiecePlacement(const QString& t_piecePlacement) const;
    Game::Side parseActiveSide(const QString& t_side) const;
    int parseFullmoveNumber(const QString& t_moveNumber) const;

    bool isSymbolPermitted(char t_ch) const;
};


