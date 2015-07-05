#include <QDebug>

#include "fenparser.h"

Board::PiecesMatrix FenParser::read(const QString& t_row)
{
    Board::PiecesMatrix pieces;

    auto splitted = t_row.split(" ");

    for (auto val : splitted)
        qDebug() << val;

    return pieces;
}
