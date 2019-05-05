//
// Created by matbr on 15/04/2019.
//

/*!
 * \file Svgfile.h
 * \class Svgfile
 * \brief Classe pour les objets Svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.5
 * \date 21 avril2019
 */

#ifndef PROJET_PISCINE_SVGFILE_H
#define PROJET_PISCINE_SVGFILE_H


#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#include <vector>


constexpr char defcol[] = "black";

class Svgfile {
private:
    std::string m_filename;
    std::ofstream m_ostrm;
    int m_width;
    int m_height;
    // Pour éviter les ouverture multiples
    static std::set <std::string> s_openfiles;

public:

    /*!
 * \fn Svgfile
 * \brief Creation du Svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
    Svgfile(std::string _filename = "output.html", int _width = 2000, int _height = 2000);

    /*!
 * \fn ~Svgfile
 * \brief destructeur de Svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    ~Svgfile();

/*!
 * \fn addLine
 * \brief Ajouter une ligne
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param color
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    void addLine(double x1, double y1, double x2, double y2, std::string color = defcol);

    /*!
 * \fn addCross
 * \brief Ajouter une croix
 * @param x
 * @param y
 * @param span
 * @param color
 * \author M. Fercoq
 * \version 0
 * \date 15 avril 2019
 */
    void addCross(double x, double y, double span, std::string color = defcol);

    /*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param text
 * @param color
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0
 * \date 15 avril 2019
 */
    void addText(double x, double y, std::string text, std::string color = defcol);

    /*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param val
 * @param color
 * \author M. Fercoq
 * \version 0
 * \date 15 avril 2019
 */
    void addText(double x, double y, double val ,std::string color);

    /*!
 * \fn addDisk
 * \brief Ajouter un disque (cercle plein --> pour les sommets)
 * @param x
 * @param y
 * @param color
 * @param clas
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 19 avril 2019
 */
    void addDisk(double x, double y,std::string color);

    /*!
 * \fn addlegende
 * \brief Ajouter une legende (--> pour les ponderations)
 * @param x1
 * @param x2
 * @param y1
 * @param y2
 * @param color
 * @param text
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    void addlegende(double x1, double x2, double y1, double y2, std::string color, std::string text);

    /*!
 * \fn addcircle
 * \brief Ajouter un cercle
 * @param x
 * @param y
 * @param r
 * @param color
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
    void addcircle(double x, double y, double r, std::string color);

    /*!
 * \fn addSoleil
 * \brief Ajouter un soleil (mouvement)
 * @param r
 * @param color
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 15 avril 2019
 */
    void addSoleil(double r, std::string color);

    /*!
 * \fn addGrid
 * \brief Ajouter une grille
 * @param span
 * @param numbering
 * @param color
 * \author M. Fercoq
 * \version 0
 * \date 15 avril 2019
 */
    void addGrid(double span = 100.0, bool numbering = true, std::string color = "lightgrey");

    void addli();

    void endli();

    /*!
 * \fn translate
 * \brief creer un groupe G qui décale les coordonnées en x et en y (effet de translation)
 * @param scale
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    void transalte(int scaleX ,int scaleY);

    /*!
 * \fn finG
 * \brief ecrit la fin d'un groupe G dans le svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    void finG();

    /*!
 * \fn addG
 * \brief ecrit le début d'un groupe G dans le svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    void addG();

    /*!
 * \fn addA
 * \brief ecrit le début d'un groupe A dans le svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    void addA();

    /*!
 * \fn finA
 * \brief ecrit la fin d'un groupe A dans le svg
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 16 avril 2019
 */
    void finA();

    /*!
 * \fn addLine
 * \brief Ajouter une ligne
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param color
 * @param clas
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 20 avril 2019
 */
    void addLine(double x1, double y1, double x2, double y2, std::string color ,std::string clas);

    /*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param text
 * @param nb
 * @param color
 * @param clas
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 18 avril 2019
 */
    void addText(double x, double y, std::string text,int nbcarac, std::string color, std::string clas);

    /*!
 * \fn addDisk
 * \brief Ajouter un disque (cercle plein --> pour les sommets)
 * @param x
 * @param y
 * @param color
 * @param clas
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 19 avril 2019
 */
    void addDisk(double x, double y, std::string color, std::string clas);

    /*!
* \fn addText
* \brief Ajouter un texte
* @param x
* @param y
* @param color
* @param clas
* \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
* \version 0.2
* \date 18 avril 2019
*/
    void addText(double x, double y, double val, std::string color, std::string clas);

    /*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param text
 * @param color
 * @param clas
 * \author M. Fercoq, BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 18 avril 2019
 */
    void addText(double x, double y, std::string text, std::string color, std::string clas);

    /*!
 * \fn addpoint
 * \brief Ajouter un point
 * @param x
 * @param y
 * @param color
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.1
 * \date 18 avril 2019
 */
    void addpoint(double x, double y, std::string color);

    /*!
 * \fn addrepere
 * \brief Dessiner un repère
 * @param x
 * @param y
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 21 avril 2019
 */
    void addrepere(int x, int y);

/*!
 * \fn addencadrer
 * \brief Dessiner l'encadrement des graphes
 * @param maxX
 * @param minX
 * @param maxY
 * @param minY
 * @param scaleX
 * @param scaleY
 * @param text
 * \author BRIONNE Mathis, MARTIN Willy, SIROT Charlotte
 * \version 0.2
 * \date 18 avril 2019
 */
    void addencadrer(int maxX, int minX, int maxY, int minY,int scaleX,int scaleY, std::string text);

    void transalte(int scale);
};

std::string makeRGB(int r, int g, int b);

std::string fillBallColor(std::string col);

#endif //PROJET_PISCINE_SVGFILE_H
