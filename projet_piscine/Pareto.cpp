
//! \file Pareto.cpp
//! \brief  les graphes admissibles sont present dans m_tab
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 16 avril 2019 21h30
//! \return

#include "Pareto.h"
#include "time.h"

//constructeur destructeur
Pareto::Pareto()
{}

Pareto::~Pareto()
{
    //for(m_sommets_tab
}
//methodes


///recherche des solutions admissibles
void Pareto::initialisation_q2(std::vector<Sommet*>& sommets,std::vector<Arete*>& aretes)
{
    std::cout<<std::endl;
    clock_t start_t,end_t;
    start_t =clock();
    std::cout<<" debut de pareto "<< start_t<<std::endl;

    //initialisation des données
    m_sommets_tab =sommets;
    m_aretes_tab = aretes;

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
        /*//test d'affichage de tout les aretes
        for(size_t i=0;i<temp_graph.size();i++)
            std::cout<<temp_graph[i];
        std::cout<<std::endl;
        //__________________________*/

        somme_aretes_temp=0;
        for(auto && j : temp_graph)
        {
            if(j==true)
                somme_aretes_temp++;
        }

        if (somme_aretes_temp==m_sommets_tab.size()-1)
        {
            //std::cout<<"t";
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

    end_t=clock();
    std::cout<<"fin de pareto "<<end_t;
}

void Pareto::fn_somP()
{

}
/*NOUVEAUTE*/

//! \fn void Pareto::calcul_front_pare()
//! \brief  non fonctionnel, pas encore tester
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.1
//! \date 17 avril 2019 15h20
//! \return

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
        if(tab[i].first== false)
            continue;

        for(size_t x=0;x<tab.size();x++)
        {
            if(tab[x].first== false||x==i)
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
}