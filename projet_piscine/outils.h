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

/*!
 * \fn totalPond
 * \brief calcul de la somme des ponderations
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
std::vector<float> totalPond(std::vector<std::pair<Arete*,bool>> kk);

/*!
 * \fn connexite
 * \brief permet de determiner la connexité d'un graphe
 * \return 1 si le graphe partiel est connexe, 0 sinon
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.7
 * \date 19 avril 2019
 */

/*!
 * \fn connexite
 * \brief permet de determiner la connexité d'un graphe
 * @param liens 
 * @param m_sommets 
 * @return 1 si le graphe partiel est connexe, 0 sinon
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.7
 * \date 19 avril 2019
 */
bool connexite(std::vector<std::pair<Arete*,bool>> liens, std::vector<Sommet*> m_sommets );

/*!
 * \deprecated
 * \fn connexite
 * \brief permet de determiner la connexité d'un graphe
 * @param liens 
 * @param m_sommets 
 * @return 1 si le graphe partiel est connexe, 0 sinon
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.4
 * \date 15 avril 2019
 */
bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*>& m_sommets );

/*!
 * \fn connexite_q2
 * \brief plus optimiser que la fonction connexite
 * \return 1 si le graphe partiel est connexe, 0 sinon
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.6
 * \date 17 avril 2019
 */
bool connexite_q2(std::vector<Arete*>& aretes,std::vector<bool>& b_aretes, std::vector<Sommet*>& m_sommets );
#endif //PROJET_PISCINE_OUTIL_H
