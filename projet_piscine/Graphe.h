/*!
 * \file Graphe.h
 * \class Graphe
 * \brief Classe representant l'objet graphe
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.4
 * \date 17 avril 2019
 */

#ifndef PROJET_PISCINE_GRAPH_H
#define PROJET_PISCINE_GRAPH_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Sommet.h"
#include "Arete.h"
#include "Svgfile.h"
#include "Pareto.h"

class Graphe {
private:
    Pareto p_pare;
    std::vector<Sommet*> m_sommets;
    std::vector<Arete*> m_aretes;

public:
    //constructeur destructeur
    Graphe(std::string& fichierGraph, std::string& fichierPoidsGraph);
    ~Graphe();

    //getter
    std::vector<Sommet*> getSommets() const{ return m_sommets;}
    std::vector<Arete*> getAretes() const{ return m_aretes;}

    //méthodes
    std::vector<std::pair<Arete*,bool>> kruskal(int num_pond);
    void initialiser_pareto()
        {p_pare.initialisation_q2(m_sommets,m_aretes);}

    void dessiner(Svgfile &s) const;
    void dessinerKruskal(Svgfile &s, std::vector<std::pair<Arete*,bool>> kk) const;
};


#endif //PROJET_PISCINE_GRAPH_H
