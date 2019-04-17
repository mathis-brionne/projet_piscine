//
// Created by Charlotte Sirot on 2019-04-15.
//

//!
//! \file Graph.cpp
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 15 avril 2019
//! \return

#include "Graphe.h"

// CRÉATION
Graphe::Graphe(std::string& fichierGraph, std::string& fichierPoidsGraph) {
    std::ifstream donneesGraph(fichierGraph);
    std::ifstream donneesPoidsGraph(fichierPoidsGraph);

    // test des fichiers
    if(!donneesGraph)
        throw std::runtime_error( "Erreur lors de l'ouverture du fichier du Graph : \""+fichierGraph+"\"");
    if(!donneesPoidsGraph)
        throw std::runtime_error( "Erreur lors de l'ouverture du fichier des Poids du Graph : \""+fichierPoidsGraph+"\"");

    int ordreGraph=0;
    donneesGraph >> ordreGraph;
    if (donneesGraph.fail())
        throw std::runtime_error("Erreur lors de la lecture de l'ordre du graphe");


    // Donnees des sommets
    std::string id_sommet;
    int x, y;

    // Récupération des sommets
    for(size_t i=0; i < ordreGraph; i++)
    {
        donneesGraph >> id_sommet;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet");

        donneesGraph >> x;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de la coordonnée en x du sommet");

        donneesGraph >> y;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de la coordonnée en y du sommet");

        Coords coords{x,y};
        // Création du sommet
        Sommet* sommet = new Sommet{id_sommet,coords};

        // Remplissage du tableau contenant tous les sommets
        m_sommets.push_back(sommet);
    }

    int tailleGraph=0;
    donneesGraph >> tailleGraph;
    if (donneesGraph.fail())
        throw std::runtime_error("Erreur lors de la lecture de la taille du graphe fichier 1");
    int tailleGraph2=0;
    donneesPoidsGraph >> tailleGraph2;
    if (donneesPoidsGraph.fail())
        throw std::runtime_error("Erreur lors de la lecture de la taille du graphe fichier 2");

    if(tailleGraph != tailleGraph2)
        throw std::runtime_error("Erreur de compatibilité");


    int nbr_ponderations=0;
    donneesPoidsGraph >> nbr_ponderations;
    if (donneesGraph.fail())
        throw std::runtime_error("Erreur lors de la lecture du nombre de ponderations sur les aretes du graphe");

    // Donnees des aretes
    std::string id_arete;
    std::string id_sommetD;
    std::string id_sommetA;
    float pond;
    std::vector<float> ponderations;

    int poubelle;

    // Récupération des aretes
    for(size_t i=0; i < tailleGraph; i++)
    {
        donneesGraph >> id_arete;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id de l arete");

        donneesGraph >> id_sommetD;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet de depart de l arete");

        donneesGraph >> id_sommetA;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet d arrivee de l arete");


        ponderations.clear();
        //lecture inutile de l'id aretes car même ordre d'organisation de l'id on ne considère que l'id du fichier 1
        donneesPoidsGraph>>poubelle;
        if(donneesPoidsGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id de l arete");

        for (int j = 0; j < nbr_ponderations; ++j)
        {
            donneesPoidsGraph >> pond;
            if(donneesPoidsGraph.fail())
                throw std::runtime_error("Probleme lors de la lecture de la ponderation de l arete");
            ponderations.push_back(pond);
        }
        // on met les données dans la cl&ss
        Sommet* sommetD = nullptr;
        Sommet* sommetA = nullptr;
        for(size_t i=0; (sommetD==nullptr||sommetA==nullptr) && (i < m_sommets.size()); i++)
        {
            if(m_sommets[i]->getID() == id_sommetD)
                sommetD = m_sommets[i];
            if(m_sommets[i]->getID() == id_sommetA)
                sommetA = m_sommets[i];
        }
        if(sommetA== nullptr||sommetD== nullptr)
            throw std::runtime_error("probleme de recherche du sommet (id)");

        Arete* arete = new Arete{id_arete, sommetD, sommetA,ponderations};

        // Remplissage du tableau contenant toutes les aretes
        m_aretes.push_back(arete);
    }
}


// DESSIN
void Graphe::dessiner(Svgfile &s) const {

    for (auto sta : m_aretes) {
        sta->dessiner(s, "blue");
    }
    for (auto sta : m_sommets) {
        sta->dessiner(s);
    }

}
void Graphe::dessinerKruskal(Svgfile &s , std::vector<std::pair<Arete*,bool>> kk) const {
    s.transalte(400);
    for (auto i  : kk) {
        if (i.second) {
            i.first->dessiner(s, "green");
        }
    }
    for (auto sta : m_sommets) {
        sta->dessiner(s);
    }
    s.finA();
}