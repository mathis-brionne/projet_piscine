//
// Created by Charlotte Sirot on 2019-04-15.
//

#include <fstream>
#include <ostream>
#include "Arete.h"

// CRÉATION
Arete::Arete(std::string id, Sommet* sommetD, Sommet* sommetA) :
    m_id{id}, m_sommetD{sommetD}, m_sommetA{sommetD} {

}

//SET
void Arete::setPonderations(std::vector<float> ponderations) {
    m_ponderations = ponderations;
}

// GET
std::string Arete::getID() const {
    return m_id;
}

Sommet* Arete::getSommetD() const {
    return m_sommetD;
}

Sommet* Arete::getSommetA() const {
    return m_sommetA;
}

float Arete::getPond(int num) const {
    return m_ponderations[num];
}


// DESSIN
void Arete::dessiner() const {

}



