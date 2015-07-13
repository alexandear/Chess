#include "gamecontroller.h"

GameController::GameController(QObject* t_parent)
    : QObject(t_parent)
{
    m_board.setFen(m_board.START_FEN);
    piecesChanged(m_board.piecesToString());
}

void GameController::nextMove(const Coordinate& t_from, const Coordinate& t_to)
{
    m_board.move(t_from, t_to);
    m_board.print();
}

