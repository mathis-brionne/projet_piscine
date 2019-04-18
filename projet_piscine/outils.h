/*!
 * \file outil.h
 * \brief  reference les fonctions outils (n'appartenant pas à des classes)
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 16 avril 2019
 */

#ifndef PROJET_PISCINE_OUTIL_H
#define PROJET_PISCINE_OUTIL_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

#include "Arete.h"
class Sommet;

std::vector<float> totalPond(std::vector<std::pair<Arete*,bool>> kk);

bool connexite(std::vector<std::pair<Arete*,bool>> liens, std::vector<Sommet*> m_sommets );
bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*>& m_sommets );

bool connexite_q2(std::vector<Arete*>& aretes,std::vector<bool>& b_aretes, std::vector<Sommet*>& m_sommets );
#endif //PROJET_PISCINE_OUTIL_H
