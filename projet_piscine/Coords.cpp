//
// Created by Charlotte Sirot on 2019-04-15.
//

#include "Coords.h"

// CRÉATION
Coords::Coords(int x, int y) :
    m_x{x}, m_y{y} {
}

// GET
int Coords::getX() {
    return m_x;
}

int Coords::getY() {
    return m_y;
}