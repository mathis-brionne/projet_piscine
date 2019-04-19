//
// Created by Charlotte Sirot on 2019-04-17.
//

/*!
 * \file menu.h
 * \brief bibliotheque pour les fonctions du menu
 * \authors SIROT Charlotte
 * \version 0.3
 * \date 18 avril 2019
 */

#ifndef PROJET_PISCINE_MENU_H
#define PROJET_PISCINE_MENU_H

#include <iostream>
#include <vector>
#include "Sommet.h"

std::pair<std::string,std::string> choix_graph();
int choix_algo();
int choix_ponderation(std::vector<float> pond);
int choix_sommetD(std::vector<Sommet*> sommets);
void choix_fin();

#endif //PROJET_PISCINE_MENU_H
