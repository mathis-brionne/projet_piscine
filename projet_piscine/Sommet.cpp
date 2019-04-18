//
// Created by Charlotte Sirot on 2019-04-15.
//

/*!
 * \file Sommet.cpp
 * \brief methodes de la classe Sommet
 * \authors BRIONNE Mathis
 * \version 0.2
 */

#include "Sommet.h"
#include "Arete.h"
#include "Svgfile.h"

/*!
 * \fn dessiner
 * \brief dessin des sommets
 * \author BRIONNE Mathis
 * \version 0.2
 * \date 15 avril 2019
 */
// DESSIN
void Sommet::dessiner(Svgfile &s )  {
    s.addG();
    s.addDisk(m_coords.getX(), m_coords.getY(), "black");
    s.addText(m_coords.getX(),m_coords.getY(),m_id,"white");
    s.finG();
}