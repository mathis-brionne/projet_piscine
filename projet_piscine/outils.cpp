
#include "outils.h"


//! \file outil.cpp
//! \brief  reference les fonctions n'appartenant pas à des classes
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.3
//! \date 17 avril 2019 8h
//! \return



/*!
 * \file outil.cpp
 * \brief  reference les fonctions n'appartenant pas à des classes
 * \authors BRIONNE Mathis, MARTIN Willy ,SIROT Charlotte
 * \version 0.3
 */

/*!
 * \fn totalPond
 * \brief calcul de la somme des ponderations
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
std::vector<float> totalPond(std::vector<std::pair<Arete*,bool>> kk)
{
    size_t nb_pond = kk[0].first->getPonderations().size();

    std::vector<float> sommes_pond;

    for(size_t i=0; i< nb_pond;i++)
    {
        sommes_pond.push_back(0);
    }

    for(size_t i=0; i < kk.size(); i++)
    {
        if(kk[i].second == true)
        {
            for(size_t j=0; j < nb_pond; j++)
            {
                // si l'arete est à 1 --> l'arete est existante
                sommes_pond[j] = sommes_pond[j] + kk[i].first->getPond(j);
            }
        }
    }
    return sommes_pond;
}
/*!
 * \fn connexite_q2
 * \brief plus optimiser que la fonction connexite
 * \return 1 si le graphe partiel est connexe, 0 sinon
 * \author MARTIN Willy
 * \version 0.6
 * \date 17 avril 2019
 */
bool connexite_q2(std::vector<Arete*>& aretes,std::vector<bool>& b_aretes, std::vector<Sommet*>& m_sommets )
{
    //on admet que les tableau aretes et b_aretes sont de même dimension

///DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
/*    ///1 ere partie de l'algorithme
    //on recupere une copie de liens, puis on erase les liens =0
    for(size_t i=0;i<aretes.size();i++)
    {
        if(!b_aretes[i])
        {
            aretes.erase(aretes.cbegin()+i);
            b_aretes.erase(b_aretes.cbegin()+i);
            i--;
        }
    }
    //si le nombre d'arete est infèrieur à l'ordre du graphe, alors il n'est pas connexe
    if(m_sommets.size()-1<aretes.size())
        return false;


    ///declaration et initialisation de la suite du prog
    // Au sein du vecteur liens on garde tout les aretes actives de notre sous graph, donc tout nos booléens sont à 1 à cette étape
    for(size_t i=0;i<aretes.size();i++)
        b_aretes[i]=false;*/
///FFFFFFFFFFFFFFFFFFFFFF

    //on stocke le numero de CC de notre sommet
    std::unordered_map<Sommet* , int> sommet_connexe; //first sommet //second numero connexe
    for(size_t i=0;i<m_sommets.size();i++)//initialisation
        sommet_connexe.insert({m_sommets[i],i});

///DDDDDDD
/*    //on stocke nos numero de CC dans cette attribut
    std::unordered_set<int> temp_connexe;
    int nb_connexe_estimation= sommet_connexe.size(); //on compte ou plus précisement estime le nombre de composante connexe
    */
///FFFFFFF

    //déclaration en constante pour eviter de recalculer à chaque appel
    size_t size_liens=aretes.size();

    ///2ème partie de l'algorithme
    // tant que on a pas vu toutes les aretes (tant qu'il y a des aretes)
    // on ajoute chaque aretes suivante
    int num_aretes=0;

    while(num_aretes<size_liens) /* utiliser la fonction "continue" */
    {
        //on prend l'arete num_aretes
        if(b_aretes[num_aretes]==false)
        {
            num_aretes++;
            continue;
        }

        else
        {
            //tant qu'elle relie 2 sommets connexe on avance num_aretes de 1, et qu'il reste des aretes
            if(sommet_connexe.find(aretes[num_aretes]->getSommetD())->second ==
                  (sommet_connexe.find((aretes[num_aretes])->getSommetA()))->second
                  &&num_aretes<size_liens)
                return false;

            ///else

            // A ce moment on a une arete qui relie 2 connexes differentes
            // on la met à 1 et on met à jour le numero connexe correspondant
               /* b_aretes[num_aretes]=false;                                              inutile*/

            int temp_num_connexe_A=(sommet_connexe.find(aretes[num_aretes]->getSommetA())->second);
            int temp_num_connexe_D=(sommet_connexe.find(aretes[num_aretes]->getSommetD())->second);
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
                /*
                 * INUTILE
                 *
                 * if(nb_connexe_estimation<=2)
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

                 */
        }
    }
    return true;
}

/* OPTIMISATION POSSIBLE :
 *
 *  on admet que nos tableaus sont de même dimension donc pas besoin de faire de test
 *
 *  on admet que les aretes ont déjà été compté et sont donc supèrieure à ordre-1 (1ere partie de l'algo à virer
 *
 *  au lieu de supprimer les aretes qui sont à false on travail avec notre tableau d'aretes
 *  on ajoute une aretes <=> elle est à 1 dans ce cas on la passe à 0
 *  tant que toute nos aretes nes sont pas à 0
 *
 *  ! si aretes relie 2 connexe aretes= 0 pas besoin du reste
 *
 *  les attributs entier pour connaitre le numéro de la compossante connexe d'un sommet peut être stocké à part ?
 *  ~~ ralenti la recherche d'un sommet mais éviter la copie des pointeur
 *
 *
 * */

/*!
 * \fn connexite
 * \brief permet de determiner la connexité d'un graphe
 * \return 1 si le graphe partiel est connexe, 0 sinon
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.7
 * \date 19 avril 2019 14h00
 */
bool connexite(std::vector<Arete*> aretes,std::vector<bool> b_aretes, std::vector<Sommet*>& m_sommets )
{
    //aretes est le tableau d'aretes principale
    //b_aretes est le tableau de booleen permettant de determiner le sous graphe
    //m_sommets correspond aux sommets du graphe initiale

    //on admet que les tableau aretes et b_aretes sont de même dimension
    /*affirmation precedente fausse la taille de b_aretes = taille aretes +1
     * afin de parcourir toute les étapes et reperer quand on s'arrete dans le sous prog précèdent*/


    ///1 ere partie de l'algorithme
    //on recupere une copie de liens, puis on erase les liens =0
    for(size_t i=0;i<aretes.size();i++)
    {
        if(!b_aretes[i])
        {
            aretes.erase(aretes.cbegin()+i);
            b_aretes.erase(b_aretes.cbegin()+i);
            i--;
        }
    }
    //si le nombre d'arete est infèrieur à l'ordre du graphe, alors il n'est pas connexe
    if(m_sommets.size()-1<aretes.size())
        return false;


    ///declaration et initialisation de la suite du prog
    // Au sein du vecteur liens on garde tout les aretes actives de notre sous graph, donc tout nos booléens sont à 1 à cette étape
    for(auto && b_arete : b_aretes)
        b_arete=false;

    //on stocke le numero de CC de notre sommet
    std::unordered_map<Sommet* , int> sommet_connexe; //first sommet //second numero connexe
    for(size_t i=0;i<m_sommets.size();i++)//initialisation
        sommet_connexe.insert({m_sommets[i],i});

    //on stocke nos numero de CC dans cette attribut
    std::unordered_set<int> temp_connexe;
    int nb_connexe_estimation= sommet_connexe.size(); //on compte ou plus précisement estime le nombre de composante connexe


    //déclaration en constante pour eviter de recalculer à chaque appel
    size_t size_liens=aretes.size();

    ///2ème partie de l'algorithme
    //tant que c'est pas connexe ou tant que on a pas ajouté toutes les aretes (tant qu'il y a des aretes)
    // on ajoute chaque aretes suivante
    int num_aretes=0;

    while(nb_connexe_estimation>1&&num_aretes<size_liens) /* utiliser la fonction "continue" */
    {
        //on prend l'arete num_aretes
        //tant qu'elle relie 2 sommets connexe on avance num_aretes de 1, et qu'il reste des aretes
        while(sommet_connexe.find(aretes[num_aretes]->getSommetD())->second ==
        (sommet_connexe.find((aretes[num_aretes])->getSommetA()))->second
                &&num_aretes<size_liens)
        num_aretes++;

        if(num_aretes<size_liens)
        {
            // A ce moment on a une arete qui relie 2 connexes differentes
            // on la met à 1 et on met à jour le numero connexe correspondant
            b_aretes[num_aretes]=true;

            int temp_num_connexe_A=(sommet_connexe.find(aretes[num_aretes]->getSommetA())->second);
            int temp_num_connexe_D=(sommet_connexe.find(aretes[num_aretes]->getSommetD())->second);
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

    return nb_connexe_estimation <= 1;
}


/*!
 * \deprecated
 * \fn connexite
 * \brief permet de determiner la connexité d'un graphe
 * \return 1 si le graphe partiel est connexe, 0 sinon
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.4
 * \date 15 avril 2019
 */
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

    return nb_connexe_estimation <= 1;
}