#include "board.h"
#include "gamecontroller.h"

#include <QDebug>

GameController::GameController(QObject* t_parent)
    : QObject(t_parent)
{
    m_board.print();
}

void GameController::nextMove(const Coordinate& t_from, const Coordinate& t_to)
{
    m_board.move(t_from, t_to);
    m_board.print();
}

