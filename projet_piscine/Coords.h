/*!
 * \file Coords.h
 * \class Coords
 * \brief Classe representant les objets coordonnees
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */

#ifndef PROJET_PISCINE_COORDS_H
#define PROJET_PISCINE_COORDS_H

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
