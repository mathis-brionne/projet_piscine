
//! \file outil.h
//! \brief  reference les fonctions n'appartenant pas à des classes
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.2
//! \date 16 avril 2019 15h00
//! \return

#ifndef PROJET_PISCINE_OUTIL_H
#define PROJET_PISCINE_OUTIL_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include "Arete.h"
class Sommet;


bool connexite(std::vector<std::pair<Arete*,bool>> liens, std::vector<Sommet*> m_sommets );
bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*> m_sommets );

#endif //PROJET_PISCINE_OUTIL_H
