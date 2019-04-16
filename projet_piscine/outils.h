//
// Created by Charlotte Sirot on 2019-04-16.
//

//
// Created by willy on 16/04/2019.
//

#ifndef PROJET_PISCINE_OUTIL_H
#define PROJET_PISCINE_OUTIL_H

#include "Graphe.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>


bool connexite(std::vector<std::pair<Arete*,bool>> liens,std::vector<Sommet*> m_sommets );

#endif //PROJET_PISCINE_OUTIL_H
