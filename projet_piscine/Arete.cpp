//
// Created by Charlotte Sirot on 2019-04-15.
//

#include <fstream>
#include <ostream>
#include <sstream>
#include "Arete.h"

#include "Svgfile.h"
#include "Sommet.h"

// DESSIN
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

