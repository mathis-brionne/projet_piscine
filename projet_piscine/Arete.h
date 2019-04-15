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
    Sommet* m_sommetD; // sommet de départ
    Sommet* m_sommetA; // sommet d'arrivée
    std::vector<float> m_ponderations;

public:
    Arete(std::string id, Sommet* sommetD, Sommet* sommetA);

    void setPonderations(std::vector<float> ponderations);

    std::string getID() const;
    Sommet* getSommetD() const;
    Sommet* getSommetA() const;
    float getPond(int num) const;

    void dessiner() const;

    ~Arete() = default;
};


#endif //PROJET_PISCINE_ARETE_H
