/*!
 * \file arete.cpp
 * \brief methodes de la Classe Arete
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \
 */

#include <fstream>
#include <ostream>
#include <sstream>
#include "Arete.h"
#include "Sommet.h"
#include "Svgfile.h"


// DESSIN

/*!
 * \file dessiner
 * \brief dessiner le graphe
 * @param s
 * @param color
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date
 */
void Arete::dessiner(Svgfile &s, std::string color) const {
    std::ostringstream oss117   ;
    for (auto i : m_ponderations) {
       oss117<< i <<";";
    }
    s.addG();
    s.addLine(getSommetD()->getCoords().getX(),getSommetD()->getCoords().getY(),getSommetA()->getCoords().getX(), getSommetA()->getCoords().getY(), color);
    s.addText((getSommetD()->getCoords().getX() + getSommetA()->getCoords().getX())/2, (getSommetD()->getCoords().getY() + getSommetA()->getCoords().getY())/2,oss117.str(),"black");
    s.finG();

}

