//
// Created by Charlotte Sirot on 2019-04-17.
//

/*!
 * \file menu.h
 * \brief bibliotheque pour les fonctions du menu
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 * \date 18 avril 2019
 */

#ifndef PROJET_PISCINE_MENU_H
#define PROJET_PISCINE_MENU_H

#include <iostream>
#include <vector>
#include "Sommet.h"

/*!
* \fn choix_graph
* \brief permet à l'utilisateur de choisir son graohe
* \return pair : les deux fichiers choisi
* \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
* \version 0.1
* \date 16 avril 2019
*/
std::pair<std::string,std::string> choix_graph();

/*!
 * \fn choix_algo
 * \brief permet à l'utilisateur de choisir quel algo appliquer à son graohe
 * \return int : le num de l'algo choisi
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.4
 * \date 19 avril 2019
 */
int choix_algo();

/*!
 * \fn choix_ponderation
 * \brief permet à l'utilisateur de choisir ponderation il veut prendre en compte pour appliquer Kruskal
 * @param pond
 * \return int : le num de la ponderation choisi
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 16 avril 2019
 */
int choix_ponderation(std::vector<float> pond);

/*!
 * \fn choix_sommetD
 * \brief permet à l'utilisateur de choisir le sommet de départ pour faire l'algo de Dikjtra
 * \return int : le num du sommet choisi
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 18 avril 2019
 */
int choix_sommetD(std::vector<Sommet*> sommets);

/*!
 * \fn choix_fin
 * \brief permet à l'utilisateur de choisir s'il quitte le programme ou s'il veut continuer
 * \return int : le num dfinu sommet choisi
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 21 avril 2019
 */
void choix_fin();

#endif //PROJET_PISCINE_MENU_H
