//
// Created by Charlotte Sirot on 2019-04-15.
//

#include <fstream>
#include <ostream>
#include <sstream>
#include "Arete.h"

#include "Svgfile.h"
#include "sommet.h"

// DESSIN
void Arete::dessiner(Svgfile &s) const {
    std::ostringstream oss117   ;
    for (auto i : m_ponderations) {
       oss117<< i <<";";
    }
    s.addLine(getSommetD()->getCoords().getX(),getSommetD()->getCoords().getY(),getSommetA()->getCoords().getX(), getSommetA()->getCoords().getY(), "black");
    s.addText((getSommetD()->getCoords().getX() + getSommetA()->getCoords().getX())/2, (getSommetD()->getCoords().getY() + getSommetA()->getCoords().getY())/2,oss117.str(),"black");

}

