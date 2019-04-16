//
// Created by willy on 15/04/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "graph.h"


//!
//! \file kruskal.c
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.3
//! \date 15 avril 2019
//! \return


//! \fn std::vector<std::pair<Arete*,bool>> kruskal(int)
//! \brief
//! \author MARTIN
//! \version 0.3
//! \date 15 avril 2019
//! \return

//on recupere dans la class graphe les sommets et aretes

std::vector<std::pair<Arete*,bool>> Graph::kruskal(int num_pond) //non pondéré
{
    /*declaration et initialisation*/
    // tableau d'aretes template
    std::vector<std::pair<Arete*,bool>> temp_liens;
    for(auto m_arete : m_aretes)
        temp_liens.emplace_back(m_arete,false);

    std::unordered_map<Sommet* , int> sommet_connexe; //first sommet //second numero connexe
    for(size_t i=0;i<m_sommets.size();i++)//initialisation
        sommet_connexe.insert({m_sommets[i],i});

    /* algo kruskal */
    //on trie les aretes par ordre du poids (en fonction d'une unique pondération
    std::sort(temp_liens.begin(), temp_liens.end(),[](std::pair<Arete*,bool> a1,std::pair<Arete*,bool> a2)
    {return (a1.first)->getPond(1)<(a2.first)->getPond(1);} );


    //on compte le nombre de composante connexe répertorié
    std::unordered_set<int> temp_connexe;
    int nb_connexe_estimation= sommet_connexe.size();
    int num_aretes =0;
    while(nb_connexe_estimation>1)//tant que c'est pas connexe (car obligatoirement connexe) on regarde chaque aretes next
    {
        //on prend l'arete n
        //tant qu'elle relie 2 sommets connexe on avance num_aretes de 1
        while((sommet_connexe.find((temp_liens[num_aretes].first)->getSommetD()))->second ==
              (sommet_connexe.find((temp_liens[num_aretes].first)->getSommetA()))->second)
            num_aretes++;
        // !!!!   si il n'y en a plus BUG car pas normal    !!!!


        // a ce moment on a une arete qui relie 2 connexes differentes
        // on le met à 1 et on met à jour le numero connexe correspondant
        temp_liens[num_aretes].second=true;

        int temp_num_connexe_A=(sommet_connexe.find(temp_liens[num_aretes].first->getSommetA())->second);
        int temp_num_connexe_D=(sommet_connexe.find(temp_liens[num_aretes].first->getSommetD())->second);

        for(auto & it :sommet_connexe)
        {
            if(temp_num_connexe_A == it.second)
                it.second=temp_num_connexe_D;
        }


        num_aretes++;
        /* Afin d'éviter de refaire à chaque fois le calcul de composante connexe,
         * On ne le refait que si on avait une estimation de 2 et que l'on a ajouté une arete ( possiblement supprimer une compossante)
         * après cet algo l'estimation est mise à jour au nombre réel de Composantes connexe*/
        if(nb_connexe_estimation==2)
        {temp_connexe.clear();
            for(auto pt : sommet_connexe)
            {
                if(temp_connexe.find(pt.second)==temp_connexe.end())
                    temp_connexe.insert(pt.second);
            }
            nb_connexe_estimation=temp_connexe.size();
        }
        else//si on est sur que notre nombre connexe n'est pas de 1
            nb_connexe_estimation--;
    }


    return temp_liens; //passage en copie de poids important
}


//! \fn bool connexite(std::vector<std::pair<Arete*,bool>> liens )
//! \brief permet de determiner la connexité d'un graphe
//! \author MARTIN
//! \version 0.1
//! \date 15 avril 2019
//! \return 1 si le graphe partiel est connexe, 0 sinon

/* methode de la class graphe*/
/*
bool connexite(std::vector<std::pair<Arete*,bool>> liens )
{
    //on recupere une copie de liens donc on erase les liens =0
    for(size_t i=0;i<liens.size();i++)
    {
        if(liens[i].second==false)
        {
            liens[i].erase();
            i--;
        }
    }
    bool connexe=false;
    int nb_aretes =0;
    for(size_t i=0;i<liens.size();i++)
    {
        if(liens[i].second==1)
            nb_aretes++;
    }
    if(m_sommets.size()-1>nb_aretes)
        return false;
    std::unordered_set<Sommet*> cc;
    std::queue<Sommet*> file;
    file.push(m_sommets[0]);
    for(int i=0;file.size()!=0;i++)
    {
        Sommet* temp =file.front();
        file.pop();
        temp->
    }
*/
/* debut BFS*/
/*    for( auto it: )
    {
        std::string nom=it->getID();
        if(relation.find(nom)==relation.end()&& nom!=id)
        {
            //si il n'est pas dans la liste
            //alors on l'ajoute à relation et file
            //std::cout<<m_id<<"  "<<nom << std::endl;
            file.push(it);
            relation.insert({nom,m_id});
        }
    }
*/
/* fin BFS*/
/*
    return true;
}
*/