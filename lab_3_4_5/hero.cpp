#include "hero.h"

Hero::Hero(int* _parms)
{
    parms[HP] = _parms[HP];
    parms[ENERGY] = _parms[ENERGY];
    parms[MOOD] = _parms[MOOD];
}

void Hero::add(int parm, int value) {
    if (parms[parm] + value <= 100) {
        parms[parm] += value;
    }
    else {
        parms[parm] = 100;
    }
}

bool Hero::isAlive() {
    if (parms[HP] < 0 || parms[ENERGY] < 0 || parms[MOOD] < 0) {
        return false;
    }
    return true;
}

int& Hero::operator[](int parm) {
    return parms[parm];
}
