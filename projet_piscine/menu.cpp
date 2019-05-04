//
// Created by Charlotte Sirot on 2019-04-16.
//

/*!
 * \file menu.cpp
 * \brief menu pour les choix de graphes / algos et / poids
 * \authors SIROT Charlotte
 * \version 0.2
 */

#include "menu.h"



int main();

 /*!
 * \fn choix_graph
 * \brief permet à l'utilisateur de choisir son graohe
 * \return pair : les deux fichiers choisi
 * \authors SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
std::pair<std::string,std::string> choix_graph()
{
    std::string fichier1;
    std::cout << ">>> MENU <<<" << std::endl << std::endl
              << "Choix du graphe :" << std::endl;

    int choix=0;

    while(choix != 1 && choix != 2 && choix != 3 && choix != 4)
    {
        std::cout << " >> 1. Broadway" << std::endl
                  << " >> 2. Cubetown" << std::endl
                  << " >> 3. Manhattan" << std::endl
                  << " >> 4. Triville" << std::endl << std::endl;

        std::cin >> choix;
        std::cout << std::endl;

        switch(choix)
        {
            case 1:
                fichier1 = "files/broadway.txt";
                choix=-1;
                while(choix != 0 && choix != 1 && choix != 2)
                {
                    std::cout << "Choix des poids (0,1 ou 2) pour Broadway :" << std::endl;
                    std::cin >> choix;
                    std::cout << std::endl;
                }
                switch(choix)
                {
                    case 0:
                        return {fichier1,"files/broadway_weights_0.txt"};
                    case 1:
                        return {fichier1,"files/broadway_weights_1.txt"};
                    case 2:
                        return {fichier1,"files/broadway_weights_2.txt"};
                }
                break;

            case 2:
                return {"files/cubetown.txt","files/cubetown_weights_0.txt"};

            case 3:
                fichier1 = "files/manhattan.txt";
                choix=-1;
                while(choix != 0 && choix != 1 && choix != 2)
                {
                    std::cout << "Choix des poids (0,1 ou 2) pour Manhattan :" << std::endl;
                    std::cin >> choix;
                    std::cout << std::endl;
                }
                switch(choix)
                {
                    case 0:
                        return {fichier1,"files/manhattan_weights_0.txt"};
                    case 1:
                        return {fichier1,"files/manhattan_weights_1.txt"};
                    case 2:
                        return {fichier1,"files/manhattan_weights_2.txt"};
                }
                break;

            case 4:
                fichier1 = "files/triville.txt";
                choix=-1;
                while(choix != 0 && choix != 1)
                {
                    std::cout << "Choix des poids (0 ou 1) pour Triville :" << std::endl;
                    std::cin >> choix;
                    std::cout << std::endl;
                }
                switch(choix)
                {
                    case 0:
                        return {fichier1, "files/triville_weights_0.txt"};
                    case 1:
                        return {fichier1, "files/triville_weights_1.txt"};
                    case 2:
                        return {fichier1, "files/triville_weights_2.txt"};
                }
                break;
        }
    }

/*
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
    }*/

}

/*!
 * \fn choix_algo
 * \brief permet à l'utilisateur de choisir quel algo appliquer à son graohe
 * \return int : le num de l'algo choisi
 * \authors SIROT Charlotte
 * \version 0.2
 * \date 17 avril 2019
 */
int choix_algo()
{
    int choix=0;

    while(choix != 1 && choix != 2 && choix != 3)
    {
        std::cout << "Que voulez-vous afficher ?" << std::endl
                  << "  >> 1. Solution selon Kruskal" << std::endl
                  << "  >> 2. Toutes les solutions de Pareto" << std::endl
                  << "  >> 3. Solution de Dijktra" << std::endl;

        std::cin >> choix;
        std::cout << std::endl;
    }
    return (int)choix;
}


/*!
 * \fn choix_algo
 * \brief permet à l'utilisateur de choisir ponderation il veut prendre en compte pour appliquer Kruskal
 * @param pond
 * \return int : le num de la ponderation choisi
 * \authors SIROT Charlotte
 * \version 0.2
 * \date 16 avril 2019
 */
int choix_ponderation(std::vector<float> pond)
{

   int choix=-1;

   while(choix < 0 && choix > pond.size()-1)
   {
       std::cout << "Avec quelle ponderation voulez-vous appliquer Kruskal ?" << std::endl
                 << "(0 --> 1ere pond / 1 --> 2e pond... etc)" << std::endl;

       std::cin >> choix;
       std::cout << std::endl;
   }
   return (int)choix;
}

/*!
 * \fn choix_sommetD
 * \brief permet à l'utilisateur de choisir le sommet de départ pour faire l'algo de Dikjtra
 * \return int : le num du sommet choisi
 * \authors SIROT Charlotte
 * \version 0.1
 * \date 18 avril 2019
 */
int choix_sommetD(std::vector<Sommet*> sommets)
{
    int choix=-1;

    while(choix < 0 && choix > sommets.size())
    {
        std::cout << "Quel est le sommet de depart pour derouler l'algorithme de Dikjtra ?" << std::endl;

        std::cin >> choix;
        std::cout << std::endl;
    }
    return (int)choix;
}

/*!
 * \fn choix_fin
 * \brief permet à l'utilisateur de choisir s'il quitte le programme ou s'il veut continuer
 * \return int : le num dfinu sommet choisi
 * \authors SIROT Charlotte
 * \version 0.1
 * \date 18 avril 2019
 */
void choix_fin()
{
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
                system("exit");
        }
    }
}