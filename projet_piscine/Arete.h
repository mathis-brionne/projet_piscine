//
// Created by Charlotte Sirot on 2019-04-15.
//

#ifndef PROJET_PISCINE_ARETE_H
#define PROJET_PISCINE_ARETE_H
#include <string>
#include <vector>

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
    float getPond(int num) const{ return m_ponderations[num];};
    //methodes
    void dessiner() const;


};


#endif //PROJET_PISCINE_ARETE_H
