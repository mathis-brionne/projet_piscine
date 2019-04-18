
//! \file dijkstra.cpp
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.02
//! \date 16 avril 2019 21h30
//! \return

#include <unordered_map>

#include "Pareto.h"


//! \fn dijkstra(size_t indice_P)
//! \brief  methodes de pareto qui permet de calculer la somme des distances
//! \authors BRIONNE, MARTIN, SIROT
//! \version 0.2
//! \date 18 avril 2019 17h00
//! \return

void Pareto::dijkstra(size_t indice_P)
{
    ///IDENTIFICATION DES SOMMETS ET DES ARETES
    std::unordered_map<Sommet*, size_t > r_sommets;
    std::unordered_map<Arete*,size_t > r_aretes;

    for(size_t i=0;i<m_sommets_tab.size();i++)
        r_sommets.insert({m_sommets_tab[i],i});
    for(size_t i=0;i<m_aretes_tab.size();i++)
        r_aretes.insert({m_aretes_tab[i],i});

    ///RECHERCHE DES ADJACENCES
    std::vector<Arete*> adj_sommets[m_sommets_tab.size()];
    for(size_t i=0;i<m_aretes_tab.size();i++)
    {
        adj_sommets[ r_sommets.find (m_aretes_tab[i]->getSommetA())->second ].push_back(m_aretes_tab[i]);
        adj_sommets[ r_sommets.find (m_aretes_tab[i]->getSommetD())->second ].push_back(m_aretes_tab[i]);
    }

    //test d'affichage des ids des aretes adjacentes
   /*
    for(size_t i=0;i<m_sommets_tab.size();i++)
    {
        std::cout<< "le sommet "<<i<<" est adjacent a : ";
        for(size_t j=0;j<adj_sommets[i].size();j++)
        {
           std::cout<< r_aretes.find(adj_sommets[i][j])->second;
        }
        std::cout<<std::endl;
    }*/

   float  infini = 30000;

   ///declaration du tableau de kruskal
    std::pair<bool,float> tab[m_sommets_tab.size()][m_sommets_tab.size()];



   for(size_t x=0;x<m_tab_bool.size();x++)
   {
       ///INITIALISATION DU TABLEAU DE DISJKSTRA
       for(size_t i=0;i<m_sommets_tab.size();i++)
           for(size_t j=0;j<m_sommets_tab.size();j++)
           {
               tab[i][j]={false,infini};
           }
       for(size_t i=0;i<m_sommets_tab.size();i++)
           tab[i][i]={true,0};

       ///boucle permettant de réaliser tout
       //on parcour notre tableau de dijkstra en hauteur
       // autrement dit on recherche les solutions de dijkstra en partant de tous les points
       size_t  h;
       size_t t;
       size_t sommet_voisin;
       std::pair<size_t ,float> mini;

       for(size_t z=0;z<m_sommets_tab.size();z++) /// z-> sommet de départ
       {
           ///on realise disjkstra à partir du sommet de départ ici z
           h=z;

           //on repete l'action le nombre de fois qu'on a de sommet car tous les sommets doivent être marqué
           for( size_t k=0;k<m_sommets_tab.size();k++)
           {
               //on marque notre sommet commet étant découvert
               tab[z][h].first=true;
               //on parcour toutes les aretes adjacente au sommet que l'on regarde
               for(size_t y=0;y<adj_sommets->size();y++)
               {
                   t=r_aretes.find(adj_sommets[h][y])->second;
                   if(m_tab_bool[x][t]==false)
                       continue;
                   ///on cherche le sommet voisin correspondant
                   // h etant l'indice du sommet que l'on explore
                   // t l'indice de l'aretes adjacente
                   if(m_aretes_tab[t]->getSommetA()==m_sommets_tab[h])
                       sommet_voisin=r_sommets.find(m_aretes_tab[t]->getSommetD())->second;
                   else if(m_aretes_tab[t]->getSommetD()==m_sommets_tab[h])
                       sommet_voisin=r_sommets.find(m_aretes_tab[t]->getSommetA())->second;

                   if(tab[z][sommet_voisin].first==false)
                   {
                      if(tab[z][sommet_voisin].second>tab[z][h].second+m_aretes_tab[t]->getPond(indice_P))
                      {
                          tab[z][sommet_voisin].second=tab[z][h].second+m_aretes_tab[t]->getPond(indice_P);
                      }
                   }
               }

               ///on recherche notre prochain sommet
               mini={-1,infini};
               for(size_t i=0;i<m_aretes_tab.size();i++)
               {
                   //attention a la premiere phase ou mini n'est pas acessble
                   if(tab[z][i].first==false && mini.second > tab[z][i].second)
                   {
                       mini.second=tab[z][i].second;
                       mini.first=i;
                   }
               }
               //if mini.first ==-1 ca veut dire qu'il n'y a plus de sommet à parcourir il y a une erreur

           }
       }
       ///Calcul de la pondération de kruskal
       //somme de toutes les pondérations du tableau de kruskal
       // ( ??on divise pour avoir une distance moyenne ??)

       /* option
        * ///RECHERCHE ET ENREGISTREMENT DU PLUS LONG CHEMIN
        */
   }
}