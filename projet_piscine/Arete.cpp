//!
//! \file Arete.cpp
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 15 avril 2019
//! \return

#include <fstream>
#include <ostream>
#include <sstream>
#include "Arete.h"
#include "Sommet.h"
#include "Svgfile.h"


/// Methode
// DESSIN
void Arete::dessiner(Svgfile &s , int scaleX ,int scaleY , std::string color ) const {
    std::ostringstream oss117   ;
    for (size_t i=0 ;i<m_ponderations.size();i++) {
        oss117 << m_ponderations[i];
        if (i <m_ponderations.size()-1)
            oss117<<";";
    }
    s.transalte(scaleX ,scaleY);
    s.addLine(getSommetD()->getCoords().getX(),getSommetD()->getCoords().getY(),getSommetA()->getCoords().getX(), getSommetA()->getCoords().getY(), color , "areteV");
    s.addText((getSommetD()->getCoords().getX() + getSommetA()->getCoords().getX())/2, (getSommetD()->getCoords().getY() + getSommetA()->getCoords().getY())/2,oss117.str(), std::stoi(m_id),"black","effetV");
    s.finG();

}

