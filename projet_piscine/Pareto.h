
//! \file Pareto.h
//! \brief  non fonctionnel, l'initialisation n'est pas complete
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.01
//! \date 16 avril 2019 21h30
//! \return

#ifndef PROJET_PISCINE_PARETO_H
#define PROJET_PISCINE_PARETO_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Svgfile.h"
#include "Arete.h"

class Arete;
class Sommet;

bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*>& m_sommets );
bool connexite_q2(std::vector<Arete*>& aretes,std::vector<bool>& b_aretes, std::vector<Sommet*>& m_sommets );



class Pareto
{
public:
    Pareto();
    ~Pareto();

    void initialisation_q2(std::vector<Sommet*>&, std::vector<Arete*>&);
    void  dessiner(Svgfile &svg);
    void fn_somP();

private:

    std::vector<Sommet*> m_sommets_tab;//liste de nos sommets repris de notre graphe
    std::vector<Arete*> m_aretes_tab;//liste de nos aretes repris de notre graphe

    std::vector<std::vector<bool>> m_tab_bool;//liste de nos sous graphe partiel admissible

    std::vector<std::vector<float>> m_tab_somP;//liste de nos pondérations pour chaque sous graphe


};

#endif //PROJET_PISCINE_PARETO_H
