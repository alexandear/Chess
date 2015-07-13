#pragma once

#include <QObject>

#include "board.h"

class GameController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString pieces READ pieces NOTIFY piecesChanged)

public:
    explicit GameController(QObject* t_parent = nullptr);
    void nextMove(const Coordinate& t_from, const Coordinate& t_to);

    const Board& board() const { return m_board; }
    Board& board() { return m_board; }

    QString pieces() const { return m_board.piecesToString(); }

signals:
    void piecesChanged(const QString& t_pieces);

public slots:

private:
    Board m_board;
};

