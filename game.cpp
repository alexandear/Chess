#include "game.h"

char Game::letter(Side t_side)
{
    switch (t_side) {
    case Side::Black:
        return 'b';
    case Side::White:
        return 'w';
    default:
        return ' ';
    }
}

QString Game::toString(Side t_side)
{
    switch (t_side) {
    case Side::Black:
        return "Black";
    case Side::White:
        return "White";
    default:
        return "Undefined";
    }
}

