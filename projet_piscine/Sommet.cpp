//
// Created by Charlotte Sirot on 2019-04-15.
//

#include "Sommet.h"
#include "Arete.h"
#include "Svgfile.h"
// CRÉATION
Sommet::Sommet(std::string id, Coords coords) :
    m_id{id}, m_coords{coords} {

}


// GET
std::string Sommet::getID() const {
    return m_id;
}

Coords Sommet::getCoords() const {
    return m_coords;
}


// DESSIN
void Sommet::dessiner(Svgfile &s )  {
    s.addG();
    s.addDisk(m_coords.getX(), m_coords.getY(), "blue");
    s.addText(m_coords.getX(),m_coords.getY(),m_id,"black");
    s.finG();
}