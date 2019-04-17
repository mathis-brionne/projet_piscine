//
// Created by Charlotte Sirot on 2019-04-16.
//

//
// Created by willy on 16/04/2019.
//

#include "outils.h"

//!
//! \file outil.cpp
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.1
//! \date 16 avril 2019
//! \return

//! \fn bool connexite(std::vector<std::pair<Arete*,bool>> liens )
//! \brief permet de determiner la connexité d'un graphe
//! \author MARTIN
//! \version 0.4
//! \date 15 avril 2019
//! \return 1 si le graphe partiel est connexe, 0 sinon

bool connexite(std::vector<std::pair<Arete*,bool>> liens,std::vector<Sommet*> m_sommets )
{
    ///1 ere partie de l'algorithme
    //on recupere une copie de liens, puis on erase les liens =0
    for(size_t i=0;i<liens.size();i++)
    {
        if(!liens[i].second)
        {
            liens.erase(liens.cbegin()+i);
            i--;
        }
    }
    //si le nombre d'arete est infèrieur à l'ordre du graphe, alors il n'est pas connexe
    if(m_sommets.size()-1<liens.size())
        return false;


    ///declaration et initialisation de la suite du prog

    // Au sein du vecteur liens on garde tout les aretes actives de notre sous graph, donc tout nos booléens sont à 1 à cette étape
    for(auto & lien : liens)
        lien.second=false;

    //on stocke le numero de CC de notre sommet
    std::unordered_map<Sommet* , int> sommet_connexe; //first sommet //second numero connexe
    for(size_t i=0;i<m_sommets.size();i++)//initialisation
        sommet_connexe.insert({m_sommets[i],i});

    //on stocke nos numero de CC dans cette attribut
    std::unordered_set<int> temp_connexe;
    int nb_connexe_estimation= sommet_connexe.size(); //on compte ou plus précisement estime le nombre de composante connexe


    //déclaration en constante pour eviter de recalculer à chaque appel
    size_t size_liens=liens.size();

    ///2ème partie de l'algorithme
    //tant que c'est pas connexe ou tant que on a pas ajouté toutes les aretes (tant qu'il y a des aretes)
    // on ajoute chaque aretes suivante
    int num_aretes=0;

    while(nb_connexe_estimation>1&&num_aretes<size_liens)
    {
        //on prend l'arete num_aretes
        //tant qu'elle relie 2 sommets connexe on avance num_aretes de 1, et qu'il reste des aretes
        while((sommet_connexe.find((liens[num_aretes].first)->getSommetD()))->second ==
              (sommet_connexe.find((liens[num_aretes].first)->getSommetA()))->second
              &&num_aretes<size_liens)
            num_aretes++;

        if(num_aretes<size_liens)
        {
            // A ce moment on a une arete qui relie 2 connexes differentes
            // on la met à 1 et on met à jour le numero connexe correspondant
            liens[num_aretes].second=true;

            int temp_num_connexe_A=(sommet_connexe.find(liens[num_aretes].first->getSommetA())->second);
            int temp_num_connexe_D=(sommet_connexe.find(liens[num_aretes].first->getSommetD())->second);
            for(auto & it :sommet_connexe)
            {
                if(temp_num_connexe_A == it.second)
                    it.second=temp_num_connexe_D;
            }

            //on passe à l'arete suivante
            num_aretes++;

            //mise en place d'une estimation afin de gagner en rapidité
            /* Afin d'éviter de refaire à chaque fois le calcul de composante connexe,
             * On ne le refait que si on avait une estimation de 2 et que l'on a ajouté une arete ( possiblement supprimer une compossante)
             * après cet algo l'estimation est mise à jour au nombre réel de Composantes connexe*/
            if(nb_connexe_estimation<=2)
            {
                temp_connexe.clear();
                for(auto pt : sommet_connexe)
                {
                    if(temp_connexe.find(pt.second)==temp_connexe.end())
                        temp_connexe.insert(pt.second);
                }
                nb_connexe_estimation=temp_connexe.size();
            }
            else//si on est sur que notre nombre connexe n'est pas de 1, au mieux il est descendu de 1
                nb_connexe_estimation--;
        }
    }

    if(nb_connexe_estimation>1)
        return false;
    else
        return true;
}