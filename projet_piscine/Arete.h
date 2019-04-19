//
// Created by Charlotte Sirot on 2019-04-15.
//

/*!
 * \file Arete.h
 * \class Arete
 * \brief Classe representant les objets aretes
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 15 avril 2019
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
    Arete(std::string& id, Sommet* sommetD, Sommet* sommetA,std::vector<float> ponderations) :
        m_id{id}, m_sommetD{sommetD}, m_sommetA{sommetA},m_ponderations{ponderations} { }


    ~Arete() = default;

    //getter
    std::string getID() const{ return m_id;}
    Sommet* getSommetD() const{ return m_sommetD;}
    Sommet* getSommetA() const{ return m_sommetA;}
    float getPond(int num) const{ return m_ponderations[num];}
    std::vector<float> getPonderations() const { return m_ponderations;}

    //methodes

    void dessiner(Svgfile &s, int scaleX, int scaleY, std::string color, std::string clas,std::string clas2) const;

    void dessiner(Svgfile &s, int scaleX, int scaleY, int nb, std::string color) const;

    void dessiner(Svgfile &s, int scaleX, int scaleY, std::string color) const;
};


#endif //PROJET_PISCINE_ARETE_H
