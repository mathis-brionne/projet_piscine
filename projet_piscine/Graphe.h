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
#include "Svgfile.h"
#include "Pareto.h"

class Graphe {
private:
    Pareto p_pare;
    std::vector<Sommet*> m_sommets;
    std::vector<Arete*> m_aretes;

public:
    //constructeur destructeur

    /*!
 * \fn Graphe
 * \brief Création d'un graphe
 * @param fichierGraph
 * @param fichierPoidsGraph
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 16 avril 2019
 */
    Graphe(std::string& fichierGraph, std::string& fichierPoidsGraph);

    /*!
 * \fn ~Graphe
 * \brief Déstruction d'un graphe
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0
 * \date 15 avril 2019
 */
    ~Graphe();

    //getter
    /*!
     * \fn getSommets
     * \brief recupérer les sommets du graphe
     * @return vector<Sommet*>
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    std::vector<Sommet*> getSommets() const{ return m_sommets;}

    /*!
 * \fn getAretes
 * \brief recupérer les aretes du graphe
 * @return vector<Arete*>
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
    std::vector<Arete*> getAretes() const{ return m_aretes;}

    //méthodes
    /*!
 * \fn kruskal
 * \brief algo Kruskal
 * @param num_pond
 * \return vector<pair<>> (l'ensemble des pointeur sur aretes avec un état d'existance ou non (0 inactif, 1 present))
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.5
 * \date 17 avril 2019
 */
    std::vector<std::pair<Arete*,bool>> kruskal(int num_pond);

    /*!
* \fn initialiser_pareto_q2
* \brief lancer pareto
* \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
* \version 0.2
* \date 17 avril 2019
*/
    void initialiser_pareto_q2()        {p_pare.initialisation_q2(m_sommets,m_aretes);}

    /*!
* \fn initialiser_pareto_q3
* \brief lancer pareto
* \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
* \version 0.2
* \date 18 avril 2019
*/
    void initialiser_pareto_q3(size_t indice_P)        {p_pare.initialisation_q3(m_sommets,m_aretes,indice_P);}


    /*!
 * \fn dessiner
 * \brief dessiner un graphe
 * @param s
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 17 avril 2019
 */
    void dessiner(Svgfile &s) const;

    /*!
 * \fn dessinerKruskal
 * \brief dessiner les solutions de Kruskal
 * @param s
 * @param kk
 * @param nb
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 * \date 20 avril 2019
 */
    void dessinerKruskal (Svgfile &s, std::vector<std::pair<Arete*,bool>> kk ,int nb) const;
    //void dessinerKruskal(Svgfile &s, std::vector<std::pair<Arete *, bool>> kk) const;

    /*!
* \fn dessinerPareto
* \brief dessiner Pareto
* @param s
* \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
* \version 0.2
* \date 17 avril 2019
*/
    void dessinerPareto(Svgfile& s)     {p_pare.dessiner(s);  }

    /*!
* \fn afficher_Console_Pareto
* \brief afficher les solutions de Pareto sur la console
* @param s
* \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
* \version 0.1
* \date 17 avril 2019
*/
    void afficher_Console_Pareto()      {p_pare.show_solution_front_pare();}

};


#endif //PROJET_PISCINE_GRAPH_H
