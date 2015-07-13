#pragma once

#include <array>
#include <memory>
#include <stdexcept>

#include "coordinate.h"
#include "game.h"

class AbstractPiece;

class Board
{
public:
    static const int BOARD_SIZE = 8;
    static const QString START_FEN;

    using PiecePtr = std::shared_ptr<AbstractPiece>;
    using PiecesMatrix = std::array<std::array<PiecePtr, BOARD_SIZE>, BOARD_SIZE>;

    Board() { }

    const PiecePtr& at(int t_rank, int t_file) const
    {
        return at({ t_rank, t_file });
    }
    PiecePtr& at(int t_rank, int t_file)
    {
        return at({ t_rank, t_file });
    }
    const PiecePtr& at(const Coordinate& t_coordinate) const
    {
        return m_pieces.at(t_coordinate.file()).at(t_coordinate.rank());
    }
    PiecePtr& at(const Coordinate& t_coordinate)
    {
        return m_pieces.at(t_coordinate.file()).at(t_coordinate.rank());
    }

    void setFen(const QString& t_fenStr);
    void setPieces(const PiecesMatrix& t_pieces) { m_pieces = t_pieces; }
    PiecesMatrix pieces() const { return m_pieces; }
    void setActiveSide(Game::Side t_side) { m_activeSide = t_side; }
    Game::Side activeSide() const { return m_activeSide; }
    void setMoveNumber(int t_moveNumber) { m_moveNumber = t_moveNumber; }

    QString piecesToString() const;
    void move(const Coordinate& t_from, const Coordinate& t_to);
    void print() const;


private:
    Game::Side m_activeSide;
    int m_moveNumber;
    PiecesMatrix m_pieces;

    void placePieces(Game::Side t_side);
};

