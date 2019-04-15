//
// Created by Charlotte Sirot on 2019-04-15.
//

#ifndef PROJET_PISCINE_SOMMET_H
#define PROJET_PISCINE_SOMMET_H
#include <string>
#include <vector>
#include "Coords.h"

class Arete;

class Sommet {
private:
    std::string m_id;
    Coords m_coords;
    std::vector<Arete*> m_aretesAdj;

public:
    Sommet(std::string id, Coords coords);

    std::vector<Arete*> setAretesAdj() const;

    std::string getID() const;
    Coords getCoords() const;
    std::vector<Arete*> getAretesAdj() const;

    void dessiner() const;

    ~Sommet() = default;
};


#endif //PROJET_PISCINE_SOMMET_H
