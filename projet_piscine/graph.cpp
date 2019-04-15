//
// Created by Charlotte Sirot on 2019-04-15.
//

#include "Graph.h"

// CRÉATION
Graph::Graph(std::string fichierGraph, std::string fichierPoidsGraph) {
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
        throw std::runtime_error("Erreur lors de la lecture de l ordre du graphe");


    // Donnees des sommets
    std::string id_sommet;
    int x, y;

    // Récupération des sommets
    for(size_t i=0; i < ordreGraph; i++)
    {
        donneesGraph >> id_sommet;
        std::cout << id_sommet << std::endl;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet");

        donneesGraph >> x;
        std::cout << x << std::endl;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de la coordonnée en x du sommet");

        donneesGraph >> y;
        std::cout << y << std::endl;
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
        throw std::runtime_error("Erreur lors de la lecture de la taille du graphe");

    // Donnees des aretes
    std::string id_arete;
    std::string id_sommetD;
    std::string id_sommetA;
    std::vector<float> ponderations;
    int nbr_ponderations=0;

    // Récupération des aretes
    for(size_t i=0; i < tailleGraph; i++)
    {
        donneesPoidsGraph >> nbr_ponderations;

        donneesPoidsGraph >> id_arete;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id de l arete");

        donneesPoidsGraph >> id_sommetD;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet de depart de l arete");

        donneesPoidsGraph >> id_sommetA;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet d arrivee de l arete");

        Sommet* sommetD = nullptr;
        Sommet* sommetA = nullptr;

        // AJOUTER CODE WILLY
        for(size_t i=0; i < m_sommets.size(); i++)
        {
            if(m_sommets[i]->getID() == id_sommetD)
                sommetD = m_sommets[i];
            if(m_sommets[i]->getID() == id_sommetA)
                sommetA = m_sommets[i];
        }

        Arete* arete = new Arete{id_arete, sommetD, sommetA};

        float pond;

        for (int j = 0; j < nbr_ponderations; ++j)
        {
            donneesPoidsGraph >> pond;
            ponderations.push_back(pond);
        }
        arete->setPonderations(ponderations);

        // Remplissage du tableau contenant toutes les aretes
        m_aretes.push_back(arete);
    }

}


// GET
std::vector<Sommet*> Graph::getSommets() const {
    return m_sommets;
}

std::vector<Arete*> Graph::getAretes() const {
    return m_aretes;
}


// DESSIN
void Graph::dessiner() const {

}