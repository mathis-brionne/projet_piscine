
//! \file Pareto.h
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.2
//! \date 17 avril 2019 19h20
//! \return

#ifndef PROJET_PISCINE_PARETO_H
#define PROJET_PISCINE_PARETO_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include "Arete.h"
#include "Sommet.h"

bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*>& m_sommets );
bool connexite_q2(std::vector<Arete*>& aretes,std::vector<bool>& b_aretes, std::vector<Sommet*>& m_sommets );


class Pareto
{
public:
    //constructeur destructeur
    Pareto();
    ~Pareto();

    //Methodes
    void initialisation_q2(std::vector<Sommet*>&, std::vector<Arete*>&);///DEPRECEATED

    void init_and_search_admis_q2();
    void init_and_calcul_pond();
    void show_solution_front_pare();

    void dijkstra(size_t indice_P);

    //PRIVER
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
