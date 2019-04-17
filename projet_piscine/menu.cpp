//
// Created by Charlotte Sirot on 2019-04-16.
//

//!
//! \file menu.cpp
//! \brief
//! \authors SIROT
//! \version 0.1
//! \date 15 avril 2019
//! \return

#include "menu.h"

std::pair<std::string,std::string> choix_graph()
{
    std::cout << "MENU " << std::endl << std::endl
              << "Choix du graphe :" << std::endl;

    int choix=0;

    while(choix != 10 && choix != 11 && choix != 12 && choix != 20 && choix != 30 && choix != 31 && choix != 32 && choix != 40 && choix != 41)
    {
        std::cout << " Broadway :" << std::endl
                  << "  >> 10. Poids 0" << std::endl
                  << "  >> 11. Poids 1" << std::endl
                  << "  >> 12. Poids 2" << std::endl << std::endl;

        std::cout << " Cubetown :" << std::endl
                  << "  >> 20. Poids 0" << std::endl << std::endl;

        std::cout << " Manhattan :" << std::endl
                  << "  >> 30. Poids 0" << std::endl
                  << "  >> 31. Poids 1" << std::endl
                  << "  >> 32. Poids 2" << std::endl << std::endl;

        std::cout << " Triville :" << std::endl
                  << "  >> 40. Poids 0" << std::endl
                  << "  >> 41. Poids 1" << std::endl << std::endl;

        std::cin >> choix;
        std::cout << std::endl;

        switch(choix)
        {
            case 10 :
                return {"files/broadway.txt","files/broadway_weights_0.txt"};
            case 11 :
                return {"files/broadway.txt","files/broadway_weights_1.txt"};
            case 12 :
                return {"files/broadway.txt","files/broadway_weights_2.txt"};

            case 20 :
                return {"files/cubetown.txt","files/cubetown_weights_0.txt"};

            case 30 :
                return {"files/manhattan.txt","files/manhattan_weights_0.txt"};
            case 31 :
                return {"files/manhattan.txt","files/manhattan_weights_1.txt"};
            case 32 :
                return {"files/manhattan.txt","files/manhattan_weights_2.txt"};

            case 40 :
                return {"files/triville.txt","files/triville_weights_0.txt"};
            case 41 :
                return {"files/triville.txt","files/triville_weights_1.txt"};
        }
    }

}

int choix_algo()
{
    int choix=0;

    while(choix != 1 && choix != 2)
    {
        std::cout << "Que voulez-vous afficher ?" << std::endl
                  << "  >> 1. Solution selon Kruskal" << std::endl
                  << "  >> 2. Toutes les solutions de Pareto" << std::endl;

        std::cin >> choix;
        std::cout << std::endl;

        switch (choix)
        {
            case 1 :
                return 1;
            case 2 :
                return 2;
        }

    }
}

int choix_ponderation(std::vector<float> pond)
{

    int choix=-1;

    while(choix < 0 && choix > pond.size()-1)
    {
        std::cout << "Avec quelle ponderation voulez-vous appliquer Kruskal ?" << std::endl
                  << "(0 --> 1ere pond / 1 --> 2e pond... etc)" << std::endl;

        std::cin >> choix;
        std::cout << std::endl;

        return (int)choix;
    }
}