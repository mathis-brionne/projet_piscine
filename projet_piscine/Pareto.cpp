
//! \file Pareto.cpp
//! \brief  les graphes admissibles sont present dans m_tab
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 16 avril 2019 21h30
//! \return

#include "Pareto.h"
//#include "time.h"
#include <ctime>

//constructeur destructeur
Pareto::Pareto()
{
}
Pareto::~Pareto()
{
    //for(m_sommets_tab
}
//methodes


///recherche des solutions admissibles
void Pareto::initialisation_q2(std::vector<Sommet*>& sommets,std::vector<Arete*>& aretes)
{
    std::cout<<std::endl;
    clock_t start_t,end_t,end_t2;
    start_t =clock();
    std::cout<<"Debut de pareto : "<< start_t<<std::endl;

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
    std::cout<<"Fin de la recherche des solutions admissible de pareto : "<<end_t<<std::endl;

    // initialisation de m_somP
    size_t nbr_pond= m_aretes_tab[0]->getPonderations().size();
    std::vector<float> ponds;
    for(size_t j=0;j<nbr_pond;j++)
        ponds.push_back(0);

    size_t nbr_sol=m_tab_bool.size();
    for(size_t i=0;i<nbr_sol;i++)
         m_tab_somP.push_back(ponds);


    // calcul de la somme des pondérations pour chaque solution
    std::cout<<"Fin de la recherche des ponderations total : ";
    this->totalPond();
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
    std::cout<<"Fin de Pareto"<<std::endl<<std::endl;
}

void Pareto::totalPond()
{
    size_t nb_pond = m_aretes_tab[0]->getPonderations().size();
    size_t nb_sol=m_tab_bool.size();

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
                    m_tab_somP[i][k] = m_tab_somP[i][k] + m_aretes_tab[j]->getPond(k);
            }

        }
    }
}

void Pareto::fn_somP(){}

void Pareto::dessiner(Svgfile &svg) {

    for (auto VecB : m_tab_bool) {
        svg.addA();
        for (size_t i =0 ; i < m_aretes_tab.size() ; i++) {
            if(VecB[i])
                m_aretes_tab[i]->dessiner(svg,0,500,"red");
        }
        svg.finA();
    }
}
