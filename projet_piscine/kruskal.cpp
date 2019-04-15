//
// Created by willy on 15/04/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

//!
//! \file kruskal.c
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.1
//! \date 15 avril 2019
//! \return


//! \fn std::vector<std::pair<Arete*,bool>> kruskal(int)
//! \brief
//! \author MARTIN
//! \version 0.1
//! \date 15 avril 2019
//! \return

std::vector<std::pair<Arete*,bool>> kruskal(int num_pond) //non pondéré
{
    //on recupere dans la class graphe les sommets et aretes

    /*declaration et initialisation*/
    // tableau d'aretes template
    std::vector<std::pair<Arete*,bool>> temp_liens;
    for(size_t i=0;i<m_aretes.size();i++)
        temp_liens.pushback({m_aretes[i],true})

    std::unordered_map<Sommet* , int> sommet_connexe; //first sommet //second numero connexe
    for(size_t i=0;i<m_sommets.size();i++)//initialisation
        sommet_connexe.pushback({m_sommets[i],i});

    /* algo kruskal */

    //on trie les aretes par ordre du poids (en fonction d'une unique pondération
    std::sort(temp_liens.begin(), temp_liens.end(),[](Arete* a1,Arete* a2){ return a1.getPond(num_pond)<a2.getPond(num_pond);})

    //on regarde chaque aretes jusque connexe

    //on compte le nombre de composante connexe répertorié
    std::unordered_set<int> temp_connexe;
    int nb_connexe_estimation= sommet_connexe.size();

    int n_aretes =0;
    while(nb_connexe_estimation>1)
    {
        //on prend l'arete n
        //!  if((sommet_connexe.find(temp_liens[n_aretes].getSommetD())).second==(sommet_connexe.find(temp_liens[n_aretes].getSommetA())).second)

        //tant qu'elle relie 2 sommets connexe on met le bool à 0
        //si il n'y en a plus BUG car pas normal

        //a ce moment on a une arete qui relie 2 connexes differentes
        // on le met à 1 et on met à jour le numero connexe correspondant


        /* on refait beaucoup de fois ca alors que si on à 3 connexe et qu'on à rétablie un seul lien on aura pas tout de connexe*/
        if(nb_connexe_estimation==2)//si on pense que c'est fini on fait une mise à jour exacte du nombre de compossante connexe
        {temp_connexe.clear();
            for(size_t i=0;i<sommet_connexe.size();i++)
            {
                if(temp_connexe.find(sommet_connexe[i].second)==temp_connexe.end())
                    temp_connexe.insert(sommet_connexe[i].second);
            }
        }
         else
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

/*methode de la class graphe*/

bool connexite(std::vector<std::pair<Arete*,bool>> liens )
{
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






    return true;
}