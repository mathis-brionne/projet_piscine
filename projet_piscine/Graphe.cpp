/*!
 * \file Graphe.cpp
 * \brief methodes de la Classe Arete
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 */

#include <sstream>
#include "Graphe.h"

/// CONSTRUCTEUR DESTRUCTEUR

/*!
 * \fn Graphe
 * \brief Création d'un graphe
 * @param fichierGraph
 * @param fichierPoidsGraph
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date
 */
Graphe::Graphe(std::string& fichierGraph, std::string& fichierPoidsGraph) {

//affichage
    std::cout<<"Recuperation des donnees du graphe : ";

    //ouverture des fichier
    std::ifstream donneesGraph(fichierGraph);
    std::ifstream donneesPoidsGraph(fichierPoidsGraph);
    // test des fichiers
    if(!donneesGraph)
        throw std::runtime_error( "Erreur lors de l'ouverture du fichier du Graph : \""+fichierGraph+"\"");
    if(!donneesPoidsGraph)
        throw std::runtime_error( "Erreur lors de l'ouverture du fichier des Poids du Graph : \""+fichierPoidsGraph+"\"");

    // Donnees des sommets
    int ordreGraph=0;
    donneesGraph >> ordreGraph;
    if (donneesGraph.fail())
        throw std::runtime_error("Erreur lors de la lecture de l'ordre du graphe");

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

    //recuperation des aretes
    int tailleGraph=0;//fichier 1
    donneesGraph >> tailleGraph;
    if (donneesGraph.fail())
        throw std::runtime_error("Erreur lors de la lecture de la taille du graphe fichier 1");
    int tailleGraph2=0;//fichier 2
    donneesPoidsGraph >> tailleGraph2;
    if (donneesPoidsGraph.fail())
        throw std::runtime_error("Erreur lors de la lecture de la taille du graphe fichier 2");

    if(tailleGraph != tailleGraph2) //fichier 1 et 2 compatible ?
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
        ponderations.clear();

        donneesGraph >> id_arete;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id de l arete");

        donneesGraph >> id_sommetD;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet de depart de l arete");

        donneesGraph >> id_sommetA;
        if(donneesGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id du sommet d arrivee de l arete");

        //lecture inutile de l'id aretes car même ordre d'organisation de l'id on ne considère que l'id du fichier 1
        donneesPoidsGraph>>poubelle;
        if(donneesPoidsGraph.fail())
            throw std::runtime_error("Probleme lors de la lecture de l id de l arete");

        for (int j = 0; j < nbr_ponderations; ++j)
        {
            donneesPoidsGraph >> pond;
            if(donneesPoidsGraph.fail())
                throw std::runtime_error("Probleme lors de la lecture des ponderations de l arete");
            ponderations.push_back(pond);
        }
        // on cherche à mettre les données dans la class
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
    std::cout << " 0K " << std::endl << std::endl;
}

/*!
 * \fn ~Graphe
 * \brief Déstruction d'un graphe
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date
 */
Graphe::~Graphe()
{
    //vider le tableau d'aretes et de sommets
}

/// Methodes
// DESSIN

/*!
 * \fn dessiner
 * \brief dessiner un graphe
 * @param s
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date
 */
void Graphe::dessiner(Svgfile &s) const {

    int minX=1000000,maxX=0,minY=1000000,maxY=0;
    for(auto j : m_sommets){
        if(j->getCoords().getX() < minX)
        {
            minX = j->getCoords().getX();
        }
        if(j->getCoords().getY() < minY)
        {
            minY = j->getCoords().getY();
        }
        if(j->getCoords().getX() > maxX)
        {
            maxX = j->getCoords().getX();
        }
        if(j->getCoords().getY() > maxY)
        {
            maxY = j->getCoords().getY();
        }
    }
    std::cout<<"max x :" << maxX << " min X :"<<minX << " max y :" << maxY << " min Y :"<<minY;
    std::ostringstream oss;
    oss << "Graphe original";
    s.addencadrer(maxX,minX,maxY,minY, 0 ,0 ,oss.str());
    for (auto sta : m_aretes)
        sta->dessiner(s,0,0, "blue");
    for (auto sta : m_sommets)
        sta->dessiner(s,0,0);
}