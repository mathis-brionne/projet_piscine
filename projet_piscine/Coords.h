#ifndef PROJET_PISCINE_COORDS_H
#define PROJET_PISCINE_COORDS_H


//! \file Coords.h
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 15 avril 2019
//! \return

class Coords {
private:
    int m_x;
    int m_y;

public:
    //constructeur destructeur
    Coords(int x, int y) : m_x{x}, m_y{y} {}
    ~Coords() = default;

    //getter
    int getX() {return m_x;}
    int getY() {return m_y;}

};

#endif //PROJET_PISCINE_COORDS_H
