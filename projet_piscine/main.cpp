#include <iostream>
#include "Graph.h"


//!
//! \file main.c
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 15 avril 2019
//! \return


int main();

int main() {
    Svgfile Svg;
    std::cout << "Projet PISCINE" << std::endl
    << "BRIONNE Mathis   MARTIN Willy   SIROT Charlotte  -  TD07"
    << std::endl << std::endl;

    std::string file1="files/manhattan.txt";
    std::string file2="files/manhattan_weights_0.txt";
    Graph graph(file1,file2);

    std::cout<<"recherche kruskal"<<std::endl;
    std::vector<std::pair<Arete*,bool>> kk;
    kk=graph.kruskal(0);

/*
    for(auto tp:kk)
    {
        std::cout<<"bool="<<tp.second
                <<" id="<<tp.first->getID()
                <<" S1="<<tp.first->getSommetD()->getID()
                <<" S2="<<tp.first->getSommetA()->getID()
                <<" pond="<<tp.first->getPond(0)<<std::endl;

    }

    std::cout << std::endl
              << "TEST LECTURE DE FICHIERS" << std::endl << std::endl
              << "Données du graph" << std::endl
              << "Sommets :" << std::endl;
              for(size_t i=0; i < (graph.getSommets()).size(); i++)
              {
                  std::cout << "  id : " << graph.getSommets()[i]->getID() << std::endl
                            << "  x : " << graph.getSommets()[i]->getCoords().getX() << std::endl
                            << "  y : " << graph.getSommets()[i]->getCoords().getY() << std::endl
                            << std::endl;
              }

    std::cout << std::endl
              << "Aretes :" << std::endl;
    for(size_t i=0; i < (graph.getAretes()).size(); i++)
    {
        std::cout << "  id : " << graph.getAretes()[i]->getID() << std::endl
                  <<" ponderation : "<<graph.getAretes()[i]->getPond(0)<<" "<<graph.getAretes()[i]->getPond(1)<<std::endl
                 << "  Sommet depart : " << std::endl
                  << "    id : " << graph.getAretes()[i]->getSommetD()->getID() << std::endl
                  << "    x : " << graph.getAretes()[i]->getSommetD()->getCoords().getX() << std::endl
                  << "    y : " << graph.getAretes()[i]->getSommetD()->getCoords().getY() << std::endl
                  << "  Sommet arrivee : " << std::endl
                  << "    id : " << graph.getAretes()[i]->getSommetA()->getID() << std::endl
                  << "    x : " << graph.getAretes()[i]->getSommetA()->getCoords().getX() << std::endl
                  << "    y : " << graph.getAretes()[i]->getSommetA()->getCoords().getY() << std::endl
                  << std::endl;

    }*/

    graph.dessiner(Svg);
    return 0;
}