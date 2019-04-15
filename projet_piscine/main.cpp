#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "Projet PISCINE" << std::endl
    << "BRIONNE Mathis   MARTIN Willy   SIROT Charlotte  -  TD07"
    << std::endl << std::endl;

    Graph graph("files/broadway.txt","files/broadway_weights_0.txt");

    std::cout << std::endl
              << "TEST LECTURE DE FICHIERS" << std::endl
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
                  << "  Sommet depart : " << std::endl
                  << "    id : " << graph.getAretes()[i]->getSommetD()->getID() << std::endl
                  << "    x : " << graph.getAretes()[i]->getSommetD()->getCoords().getX() << std::endl
                  << "    y : " << graph.getAretes()[i]->getSommetD()->getCoords().getY() << std::endl
                  << "  Sommet arrivee : " << std::endl
                  << "    id : " << graph.getAretes()[i]->getSommetA()->getID() << std::endl
                  << "    x : " << graph.getAretes()[i]->getSommetA()->getCoords().getX() << std::endl
                  << "    y : " << graph.getAretes()[i]->getSommetA()->getCoords().getY() << std::endl
                  << std::endl;
    }

    return 0;
}