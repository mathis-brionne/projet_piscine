/*!
 * \file Pareto.cpp
 * \brief  les graphes admissibles sont present dans m_tab
 * \authors BRIONNE MAthis, MARTIN Willy, SIROT Charlotte
 * \version 0.02
 */

#include "Pareto.h"
#include <ctime>
#include <sstream>

//constructeur destructeur
Pareto::Pareto()
{}

Pareto::~Pareto()
{
    //for(m_sommets_tab
}
//methodes

//! \fn void Pareto::initialisation_q2(std::vector<Sommet*>& sommets,std::vector<Arete*>& aretes)
//! \brief  initialisation des attributs + recherche des solutions admissible + calcul des ponderations de ces solutions + recherche des solutions de la frontière de Pareto
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.3
//! \date 17 avril 2019 15h50
//! \return

//recherche des solutions admissibles
/*!
 * \fn initialisation_q2
 * \brief  initialisation des attributs + recherche des solutions admissible + calcul des ponderations de ces solutions + recherche des solutions de la frontière de Pareto
 * @param sommets
 * @param aretes
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 * \date 17 avril 2019
 */
void Pareto::initialisation_q2(std::vector<Sommet*>& sommets,std::vector<Arete*>& aretes)
{
    clock_t start_t,end_t,end_t2,end_t3;
    start_t =clock();
    std::cout<<std::endl<<std::endl<<"Debut de pareto : "<< start_t<<std::endl;

    //initialisation des données
    m_sommets_tab =sommets;
    m_aretes_tab = aretes;

    /// RECHERCHE DES SOLUTIONS ADMISSIBLE
    this->init_and_search_admis_q2();
    end_t=clock();
    std::cout<<"Fin de la recherche des solutions admissibles de pareto : "<<end_t
             <<"  (temps ecoule : "<<end_t - start_t<<")"<<std::endl;

    /// initialisation de m_somP
    size_t nbr_pond= m_aretes_tab[0]->getPonderations().size();
    std::vector<float> ponds;
    for(size_t j=0;j<nbr_pond;j++)
        ponds.push_back(0);

    ///RECHERCHE DES POIDS DE CHAQUE SOUS GRAPHE
    size_t nbr_sol=m_tab_bool.size();
    for(size_t i=0;i<nbr_sol;i++)
         m_tab_somP.push_back(ponds);


    // calcul de la somme des pondérations pour chaque solution
    std::cout<<"Fin de la recherche des ponderations totales : ";
    this->totalPond();

    //Affichage des pondérations de toutes les solutions
    for (int k = 0; k < m_tab_bool.size(); ++k)
    {
        std::cout << "Solution n°" << k << " :" << std::endl
                  << " (";
        for(size_t i=0; i<m_aretes_tab[0]->getPonderations().size(); i++)
        {
            std::cout << m_tab_somP[k][i];
            if(i < nbr_pond-1)
                std::cout << ";";
        }
        std::cout << ")" << std::endl;
    }
    std::cout << std::endl;
    end_t2=clock();
    std::cout<<end_t2<<std::endl;

    ///RECHERCHE DES SOLUTIONS DE LA FRONTIERE DE PORETO
    std::cout<<"Fin de la recherche des solutions de la frontiere de Pareto : ";
    this->calcul_front_pare();
    end_t3=clock();
    std::cout<<end_t3
             <<"  (temps ecoule : "<<end_t3 - end_t2<<")"<<std::endl
             <<"  (Temps total ecoule : "<<end_t3 - start_t<<")"<<std::endl;

    //affichage des solutions de la frontière de poreto
    this->show_solution_front_pare();

///TEST
    this->dijkstra(1);
    std::cout<<"Fin de Pareto"<<std::endl<<std::endl;


}

void Pareto::initialisation_q3(std::vector<Sommet*>& sommets,std::vector<Arete*>& aretes)
{
    clock_t start_t,end_t,end_t2,end_t3;
    start_t =clock();
    std::cout<<std::endl<<"Debut de pareto avec calcul de meilleur distance: "<< start_t<<std::endl;

    //initialisation des données
    m_sommets_tab =sommets;
    m_aretes_tab = aretes;

    /*
     *
     * faire idem mais pour question 3 ( prend plus de solution partiel
     *
     * */
    /// RECHERCHE DES SOLUTIONS ADMISSIBLE
    this->init_and_search_admis_q2();
    end_t=clock();
    std::cout<<"Fin de la recherche des solutions admissible de pareto : "<<end_t<<std::endl;

    ///RECHERCHE DES POIDS DE CHAQUE SOUS GRAPHE

    /// initialisation de m_somP
    size_t nbr_pond= m_aretes_tab[0]->getPonderations().size();
    std::vector<float> ponds;
    for(size_t j=0;j<nbr_pond;j++)
        ponds.push_back(0);
    size_t nbr_sol=m_tab_bool.size();
    for(size_t i=0;i<nbr_sol;i++)
        m_tab_somP.push_back(ponds);

    /// calcul de la somme des pondérations pour chaque solution
    std::cout<<"Fin de la recherche des ponderations total : ";
    this->totalPond();

    this->dijkstra(1);

    /*
    //Affichage des pondérations de toutes les solutions
    for (int k = 0; k < m_tab_bool.size(); ++k)
    {
        std::cout << "Solution n°" << k << " :" << std::endl
                  << " (";
        for(size_t i=0; i<m_aretes_tab[0]->getPonderations().size(); i++)
        {
            std::cout << m_tab_somP[k][i];
            if(i < nbr_pond-1)
                std::cout << ";";
        }
        std::cout << ")" << std::endl;
    }
    std::cout << std::endl;*/

    end_t2=clock();
    std::cout<<end_t2<<std::endl;

    ///RECHERCHE DES SOLUTIONS DE LA FRONTIERE DE PORETO
    std::cout<<"Fin de la recherche des solutions de la frontiere de Pareto : ";
    this->calcul_front_pare();
    end_t3=clock();
    std::cout<<end_t3<<std::endl;

    //affichage des solutions de la frontière de pareto
    this->show_solution_front_pare();

    std::cout<<"Fin de Pareto"<<std::endl<<std::endl;
}

void Pareto::init_and_search_admis_q2()
{
    /// RECHERCHE DES SOLUTIONS ADMISSIBLE
    std::vector<bool> temp_graph;
    //on créé un vecteur booléen de la taille des aretes
    for(size_t i=0;i<m_sommets_tab.size()-1;i++)
        temp_graph.push_back(true);
    for(size_t i=m_sommets_tab.size()-1;i<=m_aretes_tab.size();i++)/** /!\ */
        temp_graph.push_back(false);

    size_t i=0;
    int somme_aretes_temp=0;
    while(temp_graph[m_aretes_tab.size()]!=true)
    {
        /*
        //test d'affichage de tout les aretes bool
        for(size_t i=0;i<temp_graph.size();i++)
            std::cout<<temp_graph[i];
        std::cout<<std::endl;
        */

        somme_aretes_temp=0;
        for(auto && j : temp_graph)
        {
            if(j==true)
                somme_aretes_temp++;
        }

        if (somme_aretes_temp==m_sommets_tab.size()-1)
        {
            if( connexite_q2( m_aretes_tab ,temp_graph,m_sommets_tab))
                m_tab_bool.push_back(temp_graph);
        }

        /// DEBUT COMPTEUR +1
        i=0;
        while(temp_graph[i]!=false)
        {
            temp_graph[i]=false;
            i++;
        }
        temp_graph[i]= true;
        ///FIN COMPTEUR
    }
}

/*!
 * \fn init_and_calcul_pond
 * \brief
 * \authors BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 17 avril 2019 23h20
 *
 * ne peut être effectuer que si les étapes suivante on été réalisé :
 * initialisation, recherche des solution admissible,
 *
 */
void Pareto::init_and_calcul_pond()
{

}

/*!
 * \fn show_solution_front_pare
 * \brief  affichage des solutions de la frontière de Pareto
 * \authors BRIONNE,MARTIN,SIROT
 * \version 0.1
 * \date 17 avril 2019 19h20
 *
 * ne peut être effectuer que si les étapes suivante on été réalisé :
 * initialisation, recherche des solution admissible, calcul des ponds et recherche des solutions de Pareto
 *
 */
void Pareto::show_solution_front_pare()
{
    size_t nbr_pond= m_aretes_tab[0]->getPonderations().size();
    //affichage des solutions de la frontière de Pareto
    std::cout<<std::endl<<"Les solutions de la frontiere de Pareto sont : "<<std::endl;
    std::cout<<"(nombre de solutions admissible = "<<m_front_pare.size()<<")"<<std::endl<<std::endl;
    for(size_t i=0;i<m_front_pare.size();i++)
    {
        if(m_front_pare[i]==true)
        {
            std::cout<<" Graphe admissible n"<<i<<" :"<<std::endl;
            for(size_t j=0;j<m_tab_bool[i].size();j++)
            {
                if(m_tab_bool[i][j]==true)
                {
                    std::cout<<" "<<j
                             << "   id = " << m_aretes_tab[j]->getID()
                             << "   id sommet de depart = " << m_aretes_tab[j]->getSommetD()->getID()
                             << "   id sommet de arrivee = " << m_aretes_tab[j]->getSommetA()->getID()
                             << "   ponderation = (";
                    for(size_t i=0; i < nbr_pond;i++)
                    {
                        std::cout << m_aretes_tab[j]->getPond(i);
                        if(i<nbr_pond-1)
                            std::cout << ";";
                    }
                    std::cout<<")"<<std::endl;
                }
            }
            std::cout<<std::endl;
        }

    }
}

/*!
 * \fn totalPond
 * \brief Calcul des ponderations totales pour chaque solution
 * \author SIROT Charlotte
 * \version 0.2
 * \date 17 avril 2019
 */
void Pareto::totalPond()
{
    size_t nb_pond = m_aretes_tab[0]->getPonderations().size();
    size_t nb_sol = m_tab_bool.size();

    std::vector<float> temp_pond;

    // j --> n° de l'arete
    for(size_t j=0; j < m_aretes_tab.size(); j++)
    {
        temp_pond=m_aretes_tab[j]->getPonderations();

        // i --> n° de la solution
        for(size_t i=0; i < nb_sol; i++)
        {
            if(m_tab_bool[i][j] == true)
            {
                // k --> n° de la ponderation
                for(size_t k=0; k < nb_pond; k++)
                    m_tab_somP[i][k] = m_tab_somP[i][k] + temp_pond[k];
            }

        }
    }
}



void Pareto::dessiner(Svgfile &svg) {

    int minX=1000000,maxX=0,minY=1000000,maxY=0;
    for(auto j : m_sommets_tab){
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
    float pondmax0 =0 ,pondmax1=0;
    for (size_t i =0 ; i < m_tab_somP[0].size() ;i++  )
    {
        if (pondmax0 < m_tab_somP[0][i])
            pondmax0 = m_tab_somP[0][i];
    }
    for (size_t i =0 ; i < m_tab_somP[0].size() ;i++  )
    {
        if (pondmax1 < m_tab_somP[1][i])
            pondmax1 = m_tab_somP[1][i];
    }
    std::cout<<"pondmax0 : "<<pondmax0<<std::endl;
    std::cout<<"pondmax1 : "<<pondmax1<<std::endl;
    svg.addrepere( maxX+50,2*(maxY+50));
    svg.addencadrer(maxX,minX,maxY,minY,0,maxY+50,"pareto");
    for (size_t j =0 ; j < m_tab_bool.size() ; j++) {
        svg.addA();
        for (size_t i = 0; i < m_aretes_tab.size(); i++) {
            if (m_tab_bool[j][i])
                m_aretes_tab[i]->dessiner(svg,  0,  maxY+50, "red", "arete", "effet");
        }
        for (auto Som : m_sommets_tab) {
            Som->dessiner(svg, 0,  maxY+50, "circle", "effet");
        }
        if (m_tab_somP[j][0] || m_tab_somP[j][1] != 0) {
            if (m_front_pare[j]) {
                svg.addpoint( maxX+50 + 10 * m_tab_somP[j][0],  2*(maxY+50) -10* m_tab_somP[j][1], "green");
            } else {
                svg.addpoint( maxX+50 + 10 * m_tab_somP[j][0], 2*(maxY+50) -10* m_tab_somP[j][1], "red");
            }
        }
            svg.finA();

    }
}

//! \fn void Pareto::calcul_front_pare()
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.2
//! \date 17 avril 2019 19h20
//! \return
///
/// ne peut être effectuer que si les étapes suivante on été réalisé :
/// initialisation, recherche des solution admissible, calcul des ponds

void Pareto::calcul_front_pare()
{
    std::vector<std::pair<bool,std::vector<float>>> tab;
    for(size_t i=0;i<m_tab_bool.size();i++)
        tab.push_back({true,m_tab_somP[i]});

    size_t nbr_pond;
    nbr_pond = m_aretes_tab[0]->getPonderations().size();

    bool test;
    for(size_t i=0;i<tab.size();i++)
    {
        if(!tab[i].first)
            continue;

        for(size_t x=0;x<tab.size();x++)
        {
            if(!tab[x].first || x == i)
                continue;

            test= true;
            for(size_t j=0;j<nbr_pond;j++)
            {
                if(tab[i].second[j]>tab[x].second[j])
                    test=false;
            }
            if(test==true)
                tab[x].first=false;
        }
    }
    for(size_t i=0;i<m_tab_bool.size();i++)
    {
        m_front_pare.push_back(tab[i].first);
    }

}