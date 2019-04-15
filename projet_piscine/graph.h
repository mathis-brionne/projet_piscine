//
// Created by Charlotte Sirot on 2019-04-15.
//

#ifndef PROJET_PISCINE_GRAPH_H
#define PROJET_PISCINE_GRAPH_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Sommet.h"
#include "Arete.h"

class Graph {
private:
    std::vector<Sommet*> m_sommets;
    std::vector<Arete*> m_aretes;

public:
    Graph(std::string fichierGraph, std::string fichierPoidsGraph);
    void dessiner() const;

    std::vector<Sommet*> getSommets() const;
    std::vector<Arete*> getAretes() const;

    ~Graph() = default;
};


#endif //PROJET_PISCINE_GRAPH_H
