//
// Created by Charlotte Sirot on 2019-04-15.
//

/*!
 * \file Arete.h
 * \class Arete
 * \brief Classe representant les objets aretes
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 * \date 20 avril 2019
 */

#ifndef PROJET_PISCINE_ARETE_H
#define PROJET_PISCINE_ARETE_H
#include <string>
#include <vector>
#include "Svgfile.h"

constexpr char defcolor[] = "black";

class Sommet;

class Arete {
private:
    std::string m_id;
    Sommet* m_sommetD; // sommet de depart
    Sommet* m_sommetA; // sommet d'arrivée
    std::vector<float> m_ponderations;

public:
    //constructeur detructeur
    /*!
     * \fn Arete
     * \brief Création d'une arete
     * @param id
     * @param sommetD
     * @param sommetA
     * @param ponderations
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    Arete(std::string& id, Sommet* sommetD, Sommet* sommetA,std::vector<float> ponderations) :
        m_id{id}, m_sommetD{sommetD}, m_sommetA{sommetA},m_ponderations{ponderations} { }

    /*!
     * \fn ~Arete
     * \brief Destruction d'une arete
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    ~Arete() = default;

    //getter
    /*!
     * \fn getID
     * \brief recupérer l'ID de l'arete
     * @return string
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    std::string getID() const{ return m_id;}

    /*!
     * \fn getSommetD
     * \brief recupérer le sommet de départ
     * @return Sommet* : le sommet de départ
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    Sommet* getSommetD() const{ return m_sommetD;}

    /*!
     * \fn getSommetA
     * \brief recupérer le sommet d'arrivée
     * @return Sommet* : le sommet d'arrivée
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    Sommet* getSommetA() const{ return m_sommetA;}

    /*!
     * \fn getPond
     * \brief recupérer la valeur d'une pondération
     * @param num
     * @return float : la pondération
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    float getPond(int num) const{ return m_ponderations[num];}

    /*!
     * \fn getPnderations
     * \brief recupérer toutes les pondérations
     * @return vector<float> : toutes les pondérations
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 15 avril 2019
     */
    std::vector<float> getPonderations() const { return m_ponderations;}

    //methodes

    /*!
     * \fn dessiner
     * \brief dessiner le graphe
     * @param s
     * @param color
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.3
     * \date 18 avril 2019
     */
    void dessiner(Svgfile &s, int scaleX, int scaleY, std::string color, std::string clas,std::string clas2) const;

    /*!
     * \fn dessiner
     * \brief dessiner le graphe
     * @param s
     * @param scaleX
     * @param scaleY
     * @param color
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.1
     * \date 18 avril 2019
     */
    void dessiner(Svgfile &s, int scaleX, int scaleY, int nb, std::string color) const;

    /*!
     * \fn dessiner
     * \brief dessiner le graphe
     * @param s
     * @param scaleX
     * @param scaleY
     * @param color
     * @param clas
     * @param clas2
     * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
     * \version 0.2
     * \date 20 avril 2019
     */
    void dessiner(Svgfile &s, int scaleX, int scaleY, std::string color) const;
};


#endif //PROJET_PISCINE_ARETE_H
