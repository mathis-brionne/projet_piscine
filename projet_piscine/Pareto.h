/*!
 * \file Pareto.h
 * \class Pareto
 * \brief  bibliotheque pour les fonctions permettant de faire Pareto
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 * \date 19 avril 2019
 */

#ifndef PROJET_PISCINE_PARETO_H
#define PROJET_PISCINE_PARETO_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Svgfile.h"
#include <unordered_map>
#include "Arete.h"
#include "Sommet.h"

bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*>& m_sommets );
bool connexite_q2(std::vector<Arete*>& aretes,std::vector<bool>& b_aretes, std::vector<Sommet*>& m_sommets );



class Pareto
{
public:
    //constructeur destructeur

    /*!
 * \fn Pareto
 * \brief Création de pareto
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 17 avril 2019
 */
    Pareto();

    /*!
 * \fn ~Pareto
 * \brief Déstruction de pareto
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 17 avril 2019
 */
    ~Pareto();

    //Methodes

    /*!
 * \fn initialisation_q2
 * \brief  initialisation des attributs + recherche des solutions admissibles q2 + calcul des ponderations de ces solutions + recherche des solutions de la frontière de Pareto
 * @param sommets
 * @param aretes
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 * \date 17 avril 2019
 */
    void initialisation_q2(std::vector<Sommet*>&, std::vector<Arete*>&);///DEPRECEATED

    /*!
 * \fn initialisation_q3
 * \brief initialisation des attributs + recherche des solutions admissibles q3 + calcul des ponderations de ces solutions (Dikjitra) + recherche des solutions de la frontière de Pareto
 * @param sommets
 * @param aretes
 * @param indice_P
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 19 avril 2019
 */
    void initialisation_q3(std::vector<Sommet*>& sommets,std::vector<Arete*>& aretes,size_t indice_P);

    /*!
 * \fn init_and_search_admis_q2
 * \brief recherche des solutions admissible dans le cadre de la question 2
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 17 avril 2019
 */
    void init_and_search_admis_q2();

    /*!
 * \fn init_and_search_admis_q3
 * \brief  recherche des solutions admissible dans le cadre de la question 3
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.4
 * \date 19 avril 2019
 */
    void init_and_search_admis_q3();

    void init_and_calcul_pond();

    /*!
 * \fn show_solution_front_pare
 * \brief  affichage console des solutions de la frontière de Pareto
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 17 avril 2019
 *
 * ne peut être effectuer que si les étapes suivante on été réalisé :
 * initialisation, recherche des solution admissible, calcul des ponds et recherche des solutions de Pareto
 *
 */
    void show_solution_front_pare();

    /*!
 * \fn dijkstra
 * \brief  methodes de pareto qui permet de calculer la somme des distances
 * @param indice_P
 *
 * ce sous prog recoit en paramètre l'indice de pondérations utiliser
 * il realise un dijkstra particulier en ce basant sur l'indice donnée (indice P est l'indice où est stockés les distance entre deux points
 * ce sous programme permet de calculer les distances totals (sommes) de chaque sous graphe et de mettre cette somme dans m_somP (indice_P)
 * !!! il ajoute également à m_somP une valeur en mode push_back qui est la distance maximal !!!
 *
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 18 avril 2019
 */
    void dijkstra(size_t indice_P);

    //PRIVER

    /*!
 * \fn totalPond
 * \brief Calcul des ponderations totales pour chaque solution
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 17 avril 2019
 *
 * ne peut être effectuer que si les étapes suivante on été réalisé :
 * initialisation, recherche des solution admissible,
 *
 */
    void totalPond();

    /*!
 * \fn calcul_front_pare
 * \brief  trouver les solutions appartenant à la frontière de Pareto (pour n pondérations)
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 17 avril 2019
 *
 * ne peut être effectuer que si les étapes suivante on été réalisé :
 * initialisation, recherche des solutions admissibles, calcul des ponds
 *
 */
    void calcul_front_pare();

    /*!
 * \fn dessiner
 * \brief dessiner les solutions de Pareto
 * @param svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.4
 * \date 21 avril 2019
 */
    void dessiner(Svgfile &svg);

private:

    std::vector<Sommet*> m_sommets_tab;//liste de nos sommets repris de notre graphe
    std::vector<Arete*> m_aretes_tab;//liste de nos aretes repris de notre graphe

    std::vector<std::vector<bool>> m_tab_bool;//liste de nos sous graphe partiel admissible
    std::vector<std::vector<float>> m_tab_somP;//liste de nos pondérations pour chaque sous graphe


    std::vector<bool> m_front_pare;//pareto

};

#endif //PROJET_PISCINE_PARETO_H
