//
// Created by Charlotte Sirot on 2019-04-15.
//

/*!
 * \file Sommet.h
 * \class Sommet
 * \brief Classe representant les objets Sommet
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.4
 * \date 18 avril 2019
 */

#ifndef PROJET_PISCINE_SOMMET_H
#define PROJET_PISCINE_SOMMET_H
#include <string>
#include <vector>
#include "Coords.h"
#include "Svgfile.h"

class Arete;

class Sommet{
private:
    std::string m_id;
    Coords m_coords;

public:

/*!
 * \fn Sommet
 * \brief Créer un sommet
 * @param id
 * @param coords
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
Sommet(std::string id, Coords coords) :
    m_id{id}, m_coords{coords} {}

std::string getID() const {return m_id;}
Coords getCoords() const {return m_coords;}

void dessiner(Svgfile &s ,int scaleX ,int scaleY);

/*!
 * \fn ~Sommet
 * \brief Destruction un sommet
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
~Sommet() = default;

/*!
 * \fn dessiner
 * \brief dessin des sommets
 * @param s
 * @param scaleX
 * @param scaleY
 * @param clas
 * @param clas2
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 18 avril 2019
 */
void dessiner(Svgfile &s, int scaleX, int scaleY, std::string clas, std::string clas2);
};


#endif //PROJET_PISCINE_SOMMET_H
