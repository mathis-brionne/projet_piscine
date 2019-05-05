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
/*!
 * \fn Coords
 * \brief Création de coordonnées
 * @param x
 * @param y
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
Coords(int x, int y) : m_x{x}, m_y{y} {}

/*!
 * \fn ~Coords
 * \brief Destruction des coordonnées
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
~Coords() = default;

//getter
/*!
 * \fn getX
 * \brief Recupere la coordonnée x
 * @return int : coordonnée x
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
int getX() {return m_x;}

/*!
 * \fn getY
 * \brief Recupere la coordonnée y
 * @return int : coordonnée y
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
int getY() {return m_y;}

};

#endif //PROJET_PISCINE_COORDS_H
