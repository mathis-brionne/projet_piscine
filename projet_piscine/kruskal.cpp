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


//! \fn std::vector<std::pair<Arete*,bool>> Graph::kruskal(int)
//! \brief
//! \author MARTIN
//! \version 0.5
//! \date 15 avril 2019
//! \return l'ensemble des pointeur sur aretes avec un état d'existance ou non (0 inactif, 1 present)

//on recupere dans la class graphe les sommets et aretes

std::vector<std::pair<Arete*,bool>> Graph::kruskal(int num_pond) //non pondéré
{
    ///declaration et initialisation
    // tableau d'aretes template
    std::vector<std::pair<Arete*,bool>> temp_liens;
    for(auto m_arete : m_aretes)
        temp_liens.emplace_back(m_arete,false);

    std::unordered_map<Sommet* , int> sommet_connexe; //first sommet //second numero connexe
    for(size_t i=0;i<m_sommets.size();i++)//initialisation
        sommet_connexe.insert({m_sommets[i],i});

    std::unordered_set<int> temp_connexe;
    int nb_connexe_estimation= sommet_connexe.size(); //on compte/estime le nombre de composante connexe
    int num_aretes =0;

    /// algo kruskal
    //on trie les aretes par ordre du poids (en fonction d'une unique pondération
    //la fonction sort n'accepte pas des variables aux niveaux de sa fonction, nous somme donc obligé de faire un switch
    switch (num_pond)
    {
        case 0 :
            std::sort(temp_liens.begin(), temp_liens.end(),[](std::pair<Arete*,bool> a1,std::pair<Arete*,bool> a2)
            {return (a2.first)->getPond(0) > (a1.first)->getPond(0);} );
            break;
        case 1:
            std::sort(temp_liens.begin(), temp_liens.end(),[](std::pair<Arete*,bool> a1,std::pair<Arete*,bool> a2)
            {return (a2.first)->getPond(1) > (a1.first)->getPond(1);} );
            break;
        case 2:
            std::sort(temp_liens.begin(), temp_liens.end(),[](std::pair<Arete*,bool> a1,std::pair<Arete*,bool> a2)
            {return (a2.first)->getPond(2) > (a1.first)->getPond(2);} );
            break;
        case 3:
            std::sort(temp_liens.begin(), temp_liens.end(),[](std::pair<Arete*,bool> a1,std::pair<Arete*,bool> a2)
            {return (a2.first)->getPond(3) > (a1.first)->getPond(3);} );
            break;
        default:
            throw std::runtime_error(" kruskal : numéro de pondération incorrecte");
    }

    //tant que c'est pas connexe (car obligatoirement connexe) on regarde chaque aretes next
    //si le numero d'aretes est supèrieur à la taille du tableau
    while(nb_connexe_estimation>1)
    {
        //on prend l'arete n
        //tant qu'elle relie 2 sommets connexe on avance num_aretes de 1
        while((sommet_connexe.find((temp_liens[num_aretes].first)->getSommetD()))->second ==
                (sommet_connexe.find((temp_liens[num_aretes].first)->getSommetA()))->second
                &&num_aretes<temp_liens.size())
            num_aretes++;

        if(num_aretes==temp_liens.size())// !!!! si on est or du tableau BUG car pas normal !!!!
            throw std::runtime_error("Erreur kruskal");

        // a ce moment on a une arete qui relie 2 connexes differentes
        // on la met à 1 et on met à jour le numero connexe correspondant
        temp_liens[num_aretes].second=true;

        int temp_num_connexe_A=(sommet_connexe.find(temp_liens[num_aretes].first->getSommetA())->second);
        int temp_num_connexe_D=(sommet_connexe.find(temp_liens[num_aretes].first->getSommetD())->second);

        for(auto & it :sommet_connexe)
        {
            if(temp_num_connexe_A == it.second)
                it.second=temp_num_connexe_D;
        }

        num_aretes++;

//mise en place d'une estimation afin de gagner en rapidité
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

// retourne l'ensemble du graphe ( pointeur sur aretes et booléen d'activation ou non des aretes
/// attention -> passage en copie => poids important (possibilité de le déclarer en pointeur avec passage du pointeur)
    return temp_liens;
}



//! \fn bool connexite(std::vector<std::pair<Arete*,bool>> liens )
//! \brief permet de determiner la connexité d'un graphe
//! \author MARTIN
//! \version 0.1
//! \date 15 avril 2019
//! \return 1 si le graphe partiel est connexe, 0 sinon

bool Graph::connexite(std::vector<std::pair<Arete*,bool>> liens )
{
    ///déclaration et initialisation

    ///algorithme
    //on recupere une copie de liens, puis on erase les liens =0
    for(size_t i=0;i<liens.size();i++)
    {
        if(!liens[i].second)
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

    /// debut BFS
    for( auto it: )
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

    /// fin BFS

    return true;
}
