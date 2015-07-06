#pragma once

#include <QString>

struct Game
{
    enum class Side
    {
        Black,
        White
    };

    static char letter(Side t_side);
    static QString toString(Side t_side);
};


