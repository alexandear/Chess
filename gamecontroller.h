#pragma once

#include <QObject>

#include "board.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QObject* t_parent = nullptr);
    void nextMove(const Coordinate& t_from, const Coordinate& t_to);

    const Board& board() const { return m_board; }
    Board& board() { return m_board; }

signals:

public slots:

private:
    Board m_board;
};

