//
// Created by Charlotte Sirot on 2019-04-15.
//

//!
//! \file Graph.h
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 15 avril 2019
//! \return

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
    ~Graphe() = default;
    //getter
    std::vector<Sommet*> getSommets() const{ return m_sommets;}
    std::vector<Arete*> getAretes() const{ return m_aretes;}


    //méthodes
    std::vector<std::pair<Arete*,bool>> kruskal(int num_pond);

    void initialiser_pareto(){p_pare.initialisation_q2(m_sommets,m_aretes);}


    void dessiner(Svgfile &s) const;
    void dessinerKruskal(Svgfile &s, std::vector<std::pair<Arete*,bool>> kk) const;
};


#endif //PROJET_PISCINE_GRAPH_H
