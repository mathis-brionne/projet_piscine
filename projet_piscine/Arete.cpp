/*!
 * \file Arete.cpp
 * \brief methodes de la Classe Arete
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \
 */

#include <fstream>
#include <ostream>
#include <sstream>
#include "Arete.h"
#include "Sommet.h"
#include "Svgfile.h"


/// Methode
// DESSIN

/*!
 * \fn dessiner
 * \brief dessiner le graphe
 * @param s
 * @param color
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.3
 * \date 18 avril 2019
 */
void Arete::dessiner(Svgfile &s , int scaleX ,int scaleY ,int nb, std::string color) const {
    std::ostringstream oss117;
    oss117 << m_ponderations[nb];
    s.transalte(scaleX ,scaleY);
    s.addLine(getSommetD()->getCoords().getX(),getSommetD()->getCoords().getY(),getSommetA()->getCoords().getX(), getSommetA()->getCoords().getY(), color , "areteV");
    s.addText((getSommetD()->getCoords().getX() + getSommetA()->getCoords().getX())/2, (getSommetD()->getCoords().getY() + getSommetA()->getCoords().getY())/2,oss117.str(), std::stoi(m_id),"black","effetV");
    s.finG();

}

/*!
 * \fn dessiner
 * \brief dessiner le graphe
 * @param s
 * @param scaleX
 * @param scaleY
 * @param color
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 18 avril 2019
 */
void Arete::dessiner(Svgfile &s , int scaleX ,int scaleY , std::string color) const {
    std::ostringstream oss117   ;
    for (size_t i=0 ;i<m_ponderations.size();i++) {
        oss117 << m_ponderations[i];
        if (i <m_ponderations.size()-1)
            oss117<<";";
    }
    s.transalte(scaleX ,scaleY);
    s.addLine(getSommetD()->getCoords().getX(),getSommetD()->getCoords().getY(),getSommetA()->getCoords().getX(), getSommetA()->getCoords().getY(), color , "areteV");
    s.addText((getSommetD()->getCoords().getX() + getSommetA()->getCoords().getX())/2, (getSommetD()->getCoords().getY() + getSommetA()->getCoords().getY())/2,oss117.str(), std::stoi(m_id),"black","effetV");
    s.finG();

}

/*!
 * \fn dessiner
 * \brief dessiner le graphe
 * @param s
 * @param scaleX
 * @param scaleY
 * @param color
 * @param clas
 * @param clas2
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 20 avril 2019
 */
void Arete::dessiner(Svgfile &s , int scaleX ,int scaleY , std::string color , std::string clas, std::string clas2) const {
    std::ostringstream oss117   ;
    for (size_t i=0 ;i<m_ponderations.size();i++) {
        oss117 << m_ponderations[i];
        if (i <m_ponderations.size()-1)
            oss117<<";";
    }
    s.transalte(scaleX ,scaleY);
    s.addLine(getSommetD()->getCoords().getX(),getSommetD()->getCoords().getY(),getSommetA()->getCoords().getX(), getSommetA()->getCoords().getY(), color , clas);
    s.addText((getSommetD()->getCoords().getX() + getSommetA()->getCoords().getX())/2, (getSommetD()->getCoords().getY() + getSommetA()->getCoords().getY())/2,oss117.str(), std::stoi(m_id),"black",clas2);
    s.finG();

}