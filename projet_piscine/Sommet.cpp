//
// Created by Charlotte Sirot on 2019-04-15.
//

//!
//! \file Sommet.cpp
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 15 avril 2019
//! \return

#include "Sommet.h"
#include "Arete.h"
#include "Svgfile.h"

// DESSIN
void Sommet::dessiner(Svgfile &s ,int scaleX ,int scaleY )  {
    s.transalte(scaleX ,scaleY);
    s.addDisk(m_coords.getX(), m_coords.getY(), "blue", "circleV");
    s.addText(m_coords.getX(),m_coords.getY(),m_id, std::stoi(m_id),"black", "effetV");
    s.finG();
}