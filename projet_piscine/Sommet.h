//
// Created by Charlotte Sirot on 2019-04-15.
//

//!
//! \file Sommet.h
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.03
//! \date 15 avril 2019
//! \return

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
    Sommet(std::string id, Coords coords) :
        m_id{id}, m_coords{coords} {}

    std::string getID() const {return m_id;}
    Coords getCoords() const {return m_coords;}

    void dessiner(Svgfile &s ,int scaleX ,int scaleY);

    ~Sommet() = default;
};


#endif //PROJET_PISCINE_SOMMET_H
