//
// Created by Charlotte Sirot on 2019-04-15.
//

#include "Sommet.h"

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
void Sommet::dessiner() const {

}