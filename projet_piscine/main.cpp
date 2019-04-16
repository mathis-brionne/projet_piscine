#include <iostream>
#include "Graph.h"


//!
//! \file main.cpp
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 15 avril 2019
//! \return


int main();
std::pair<std::string,std::string> choix_graph();
int choix_algo();

int main() {
    Svgfile Svg;
    std::cout << "Projet PISCINE" << std::endl
    << "BRIONNE Mathis   MARTIN Willy   SIROT Charlotte  -  TD07"
    << std::endl << std::endl;

    std::pair<std::string,std::string> fichiers;
    fichiers = choix_graph();

    std::string file1=fichiers.first;
    std::string file2=fichiers.second;
    Graph graph(file1,file2);

    int algo = 0;
    algo = choix_algo();

    std::vector<std::pair<Arete*,bool>> kk;
    if(algo == 1)
    {
        std::cout<<"recherche kruskal"<<std::endl;

        kk=graph.kruskal(0);

        for(auto tp:kk)
        {
            std::cout<<"bool="<<tp.second
                     <<" id="<<tp.first->getID()
                     <<" S1="<<tp.first->getSommetD()->getID()
                     <<" S2="<<tp.first->getSommetA()->getID()
                     <<" pond="<<tp.first->getPond(0)<<std::endl;

        }
    }

    /*if(algo==2)
    {}*/


    std::cout << std::endl
              << "TEST LECTURE DE FICHIERS" << std::endl << std::endl
              << "Donnees du graphe" << std::endl
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
                  << "  ponderation : "<<graph.getAretes()[i]->getPond(0)<<" "<<graph.getAretes()[i]->getPond(1)<<std::endl
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

    /*
    std::vector<float> sommes_pond;
    graph.totalPond(kk) = sommes_pond;

    for(size_t i=0; i<graph.getAretes().size(); ++i)
    {
        std::cout << <<
        for(size_t j=0; j<sommes_pond.size(); j++)
        {
            std::cout << sommes_pond[j] << "  " << std::endl;
        }
    }*/


    graph.dessiner(Svg);

    if(algo == 1)
        graph.dessinerKruskal(Svg ,kk);

    //place la a l'arrache...
    /*int choix;

    while(choix != 1 && choix != 2)
    {
        std::cout << "Voulez-vous afficher un autre graphe ?" << std::endl
                  << "  1. Oui" << std::endl
                  << "  2. Non" << std::endl << std::endl;
        std::cin >> choix;
        std::cout << std::endl;

        switch(choix)
        {
            case 1 :
                main();
                break;
            case 2:
                return 0;
        }
    }*/


    return 0;
}