#pragma once

#include <tuple>
#include <QStringList>

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

    std::tuple<Board::PiecesMatrix, Game::Side, int>
    read(const QString& t_fenRow) const;

private:
    Board::PiecesMatrix parsePiecePlacement(const QString& t_piecePlacement) const;
    Game::Side parseActiveSide(const QString& t_side) const;
    int parseFullmoveNumber(const QString& t_moveNumber) const;

    bool isSymbolPermitted(char t_ch) const;

    QStringList reversed(const QStringList& t_list) const;
};


struct FenParserError : public std::runtime_error
{
    FenParserError(const std::string& msg)
        : std::runtime_error("FenParserError: " + msg)
    {
    }
};

