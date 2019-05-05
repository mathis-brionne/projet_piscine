/*!
 * \file Pareto.h
 * \class Pareto
 * \brief  bibliotheque pour les fonctions permettant de faire Pareto
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 17 avril 2019
 */

#ifndef PROJET_PISCINE_PARETO_H
#define PROJET_PISCINE_PARETO_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Svgfile.h"
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

    //Methodes
    void initialisation_q2(std::vector<Sommet*>&, std::vector<Arete*>&);///DEPRECEATED

    void init_and_search_admis_q2(std::vector<Sommet*>&, std::vector<Arete*>&);
    void init_and_calcul_pond();
    void show_solution_front_pare();

    //PRIVER
    void totalPond();

    void calcul_front_pare();

    void fn_somP();

    void dessiner(Svgfile &svg);

private:

    std::vector<Sommet*> m_sommets_tab;//liste de nos sommets repris de notre graphe
    std::vector<Arete*> m_aretes_tab;//liste de nos aretes repris de notre graphe

    std::vector<std::vector<bool>> m_tab_bool;//liste de nos sous graphe partiel admissible

    std::vector<std::vector<float>> m_tab_somP;//liste de nos pondérations pour chaque sous graphe


    std::vector<bool> m_front_pare;//pareto


};

#endif //PROJET_PISCINE_PARETO_H
