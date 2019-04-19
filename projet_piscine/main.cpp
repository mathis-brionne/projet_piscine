
/*!
 * \file main.cpp
 * \brief
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.02
 * \date 15 avril 2019
 * \
 */

#include <iostream>
#include "Graphe.h"
#include "outils.h"
#include "menu.h"

int main();

/*!
 * \fn main
 * \brief Fonction principale : execution
 * \version 0.3
 * \date 19/04/2019 10h50
 * \return 0 --> fin du programme
 */
int main() {
    Svgfile Svg;
    std::cout << "Projet PISCINE" << std::endl
    << "BRIONNE Mathis   MARTIN Willy   SIROT Charlotte  -  TD07"
    << std::endl << std::endl;

    std::pair<std::string,std::string> fichiers;
    fichiers = choix_graph();

    std::string file1=fichiers.first;
    std::string file2=fichiers.second;
    Graphe graph(file1,file2);

    int algo = 0;
    algo = choix_algo();
    std::vector<std::vector<std::pair<Arete*,bool>>> kks;

    if(algo == 1)
    {
        for(size_t i = 0 ; i < graph.getAretes()[0]->getPonderations().size();i++)
        {
            std::cout<<"Recherche kruskal en fonction de la pond "<<i<<" : ";
            kks.push_back(graph.kruskal(i));
            std::cout<<"OK"<<std::endl;
        }
        std::cout<<"Fin de la recherche des sous graphe de kruskal"<<std::endl<<std::endl;

        /*
         * Proposer à l'utilisateur de dessiner ou d'afficher à la console les graphes obtenues avec leur pondération total
         * */

        std::cout<<"Voulez-vous dessiner les sous-graphes obtenues ? "
                <<std::endl<<"   0. NON"
                <<std::endl<<"   1. OUI"<<std::endl;

        int choix=0;
        std::cin>>choix;

        if(choix==1)
        {
            //DESSIN
            graph.dessiner(Svg);
            for(size_t i = 0 ; i < graph.getAretes()[0]->getPonderations().size();i++)
                graph.dessinerKruskal(Svg ,kks[i] , i );
            Svg.~Svgfile();
            system("output.html");

        }

        /*
        //affichage de toutes les aretes de kruskal/des solutions admissible
        for(auto tp:kk)
        {
            std::cout<<"bool="<<tp.second
                     <<" id="<<tp.first->getID()
                     <<" S1="<<tp.first->getSommetD()->getID()
                     <<" S2="<<tp.first->getSommetA()->getID()
                     <<" pond="<<tp.first->getPond(0)<<std::endl;
        }*/
    }

    if(algo==2)
    {
        graph.initialiser_pareto_q2();


        /*
         * Proposer à l'utilisateur de dessiner ou d'afficher à la console les graphes obtenues avec leur pondération total
         * */

        std::cout<<" Voulez-vous afficher les graphes obtenue ?"<<std::endl
                <<" 0. NON"<<std::endl
                <<" 1. OUI en mode graphique"<<std::endl
                <<" 2. OUI en mode console"<<std::endl;
        int choix=0;
        std::cin>>choix;
        if(choix==1)
        {
            //DESSIN
            graph.dessinerPareto(Svg);
            graph.dessiner(Svg);
            Svg.~Svgfile();
            system("output.html");
        }
        if(choix==2)
            graph.afficher_Console_Pareto();

    }
    if(algo==3)
    {
        graph.initialiser_pareto_q3();
        graph.dessinerPareto(Svg);
        //DESSIN
        graph.dessiner(Svg);

        Svg.~Svgfile();
        system("output.html");

    }


/*
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

    }*/







    /*
    int choix;

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


    Svg.~Svgfile();
    // Continuer ou Quitter ?
    choix_fin();

    return 0;
}