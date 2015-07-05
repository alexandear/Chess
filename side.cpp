#include "side.h"


QString toString(Side t_side)
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

