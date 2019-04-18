/*!
 * \file Pareto.h
 * \class Pareto
 * \brief  bibliotheque pour les fonctions permettant de faire Pareto
 * \authors BRIONNE,MARTIN,SIROT
 * \version 0.1
 * \date 17 avril 2019
 */

#ifndef PROJET_PISCINE_PARETO_H
#define PROJET_PISCINE_PARETO_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Arete.h"
#include "Sommet.h"

//class Sommet;


bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*>& m_sommets );
bool connexite_q2(std::vector<Arete*>& aretes,std::vector<bool>& b_aretes, std::vector<Sommet*>& m_sommets );


class Pareto
{
public:
    Pareto();
    ~Pareto();

    void initialisation_q2(std::vector<Sommet*>&, std::vector<Arete*>&);
    void totalPond();

    void calcul_front_pare();


private:

    std::vector<Sommet*> m_sommets_tab;//liste de nos sommets repris de notre graphe
    std::vector<Arete*> m_aretes_tab;//liste de nos aretes repris de notre graphe

    std::vector<std::vector<bool>> m_tab_bool;//liste de nos sous graphe partiel admissible
    std::vector<std::vector<float>> m_tab_somP;//liste de nos pondérations pour chaque sous graphe


    std::vector<bool> m_front_pare;

};

#endif //PROJET_PISCINE_PARETO_H
