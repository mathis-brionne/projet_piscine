//
// Created by Charlotte Sirot on 2019-04-16.
//

//!
//! \file sommes_pond.cpp
//! \brief
//! \authors BRIONNE,MARTIN,SIROT
//! \version 0.01
//! \date 16 avril 2019
//! \return

#include <iostream>
#include "Arete.h"
#include <vector>

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