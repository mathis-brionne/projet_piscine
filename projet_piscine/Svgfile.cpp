/*!
 * \file Svgfile.cpp
 * \brief ensemble des methodes Svg
 * \author BRIONNE Mathis
 * \version 0.2
 */

#include "Svgfile.h"
#include <iostream>
#include <sstream>

const std::string svgHeader =
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
        "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"  xmlns:xlink=\"http://www.w3.org/1999/xlink\" ";

/// Effets "Boule en relief", voir données à la fin de ce fichier
extern const std::string svgBallGradients;

std::set<std::string> Svgfile::s_openfiles;

/*!
 * \fn Svgfile
 * \brief Creation du Svg
 * \author BRIONNE Mathis
 * \version 0.1
 * \date 15 avril 2019
 */
Svgfile::Svgfile(std::string _filename, int _width, int _height) :
        m_filename{_filename}, m_width{_width}, m_height{_height} {

    std::cout << "Opening SVG output file : "
              << m_filename << std::endl;

    if (s_openfiles.count(m_filename))
        throw std::runtime_error("File " + m_filename + " already open !");

    m_ostrm.open(m_filename);
    s_openfiles.insert(m_filename);

    if (!m_ostrm) {
        std::cout << "Problem opening " << m_filename << std::endl;
        throw std::runtime_error("Could not open file " + m_filename);
    }

    std::cout << "OK" << std::endl;

    // Writing the header into the SVG file
    m_ostrm << svgHeader;
    m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\" viewBox=\"0 0 2000 2000\">\n\n";

}

/*!
 * \fn ~Svgfile
 * \brief destructeur de Svg
 * \author BRIONNE Mathis
 * \version 0.1
 * \date 16 avril 2019
 */
Svgfile::~Svgfile() {
    // Writing the gradients into the SVG file
    m_ostrm << svgBallGradients;
    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);
    // No need to explicitly close the ofstream object (automatic upon destruction)
}

/*!
 * \fn attrib
 * \brief
 * @tparam T
 * @param name
 * @param val
 * \return string
 * \author BRIONNE Mathis
 * \version
 * \date
 */
// Helper templated function
template<typename T>
std::string attrib(std::string name, T val) {
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}

/*!
 * \fn attrib
 * \brief
 * @param name
 * @param commande
 * \return string
 * \author BRIONNE Mathis
 * \version
 * \date
 */
std::string attrib(std::string name, std::string commande) {
    std::ostringstream oss;
    oss << name << "=\"" << commande << "\" ";
    return oss.str();
}

/*!
 *\fn attrib
 * @param name
 * @param champs
 * @param champs2
 * \return string
 * \author BRIONNE Mathis
 * \version
 * \date
 */
std::string attrib(std::string name, std::string champs ,double champs2) {
    std::ostringstream oss;
    oss << name << "=\"" << champs<<champs2 << "\" ";
    return oss.str();
}

/*!
 * \fn attrib
 * \brief
 * @param name
 * @param x
 * @param y
 * @param tourne
 * @param xSatelite
 * \return string
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
std::string attrib(std::string name, double x, double y, double tourne, double xSatelite) {
    int rayon = (x - xSatelite);
    if (tourne == 1)
        rayon = 0;
    std::ostringstream oss;
    oss << name << "=\"" << "M" << " " << x << " " << y << " " << "a" << " " << rayon << " " << rayon << " 0 0 0 "
        << -(2 * rayon) << " " << "0 " << " " << "a" << rayon << " " << rayon << " 0 0 0 " << (2 * rayon) << " "
        << "0 Z" << "\"";
    return oss.str();
}

/*!
 * \fn attrib
 * \brief
 * @param name
 * @param champs
 * @param nom
 * @param champs2
 * \return string
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
std::string attrib(std::string name, std::string champs, std::string nom, std::string champs2) {
    std::ostringstream oss;
    oss << name << "=\"" << champs << champs2 << nom << "\" ";
    return oss.str();
}

/*!
 * \fn attrib
 * \brief
 * @param name
 * @param nom
 * @param champs
 * \return string
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
std::string attrib(std::string name, std::string nom, std::string champs) {
    std::ostringstream oss;
    oss << name << "=\"" << champs << nom << "\" ";
    return oss.str();
}

/*!
 * \fn attrib
 * \brief
 * @param name
 * @param champs
 * @param x
 * @param y
 * @param champs2
 * \return string
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
std::string attrib(std::string name, std::string champs, double x, double y, std::string champs2) {
    std::ostringstream oss;
    oss << name << "=\"" << champs << -x << "," << -y << champs2 << "\"";
    return oss.str();
}

/*!
 * \fn attrib
 * \brief
 * @param name
 * @param scaleN
 * @param scaleB
 * \return string
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
std::string attrib(std::string name, int scaleN, int scaleB) {
    std::ostringstream oss;
    oss << name << "=\"" << scaleN << "," << scaleB << "\" ";
    return oss.str();
}

/*!
 * \fn addSoleil
 * \brief
 * @param r
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addSoleil(double r, std::string color) {
    m_ostrm << "<path "
            << attrib("id", "motionPath")
            << attrib("fill", "none")
            << attrib("stroke", "black")
            << attrib("d", "M 100 100 Q150 50 1000 100")
            << "/>\n"
            << "<circle "
            << attrib("id", color)
            << attrib("r", r)
            << attrib("fill", color)
            << "/>\n"
            << "<animateMotion "
            << "xlink:href=\"#" << color << "\" "
            << attrib("begin", "0s")
            << attrib("fill", "freeze")
            << attrib("dur", "5")
            << attrib("repeatCount", "indefinite")
            << ">\n"
            << "<mpath xlink:href=\"#motionPath\" "
            << "/>\n"
            << "</animateMotion>\n";

}

/*!
 * \fn addDisk
 * \brief Ajouter un disque (cercle plein --> pour les sommets)
 * @param x
 * @param y
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addDisk(double x, double y,std::string color) {
    m_ostrm << "<line "
            << attrib("x1", x)
            << attrib("y1", y)
            << attrib("x2", x)
            << attrib("y2", y)
            << attrib("stroke", color)
            << attrib("class","circle")
            << "/>\n";
}

/*!
 * \fn addDisk
 * \brief Ajouter un disque (cercle plein --> pour les sommets)
 * @param x
 * @param y
 * @param color
 * @param clas
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addDisk(double x, double y,std::string color,std::string clas) {
    m_ostrm << "<line "
            << attrib("x1", x)
            << attrib("y1", y)
            << attrib("x2", x)
            << attrib("y2", y)
            << attrib("stroke", color)
            << attrib("class",clas)
            << "/>\n";
}

/*!
 * \fn addlegende
 * \brief Ajouter une legende (--> pour les ponderations)
 * @param x1
 * @param x2
 * @param y1
 * @param y2
 * @param color
 * @param text
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addlegende(double x1, double x2, double y1, double y2, std::string color, std::string text) {
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke-dasharray", 10, 5)
            << "<text "
            << attrib("x", x1 + 5)
            << attrib("y", y1 + 50)
            << attrib("fill", color)
            << "transform=\"translate(" << -5 << "," << 5 << ")\""
            << ">" << text << "</text>\n"
            << "/>\n";
}

/*!
 * \fn addcircle
 * \brief Ajouter un cercle
 * @param x
 * @param y
 * @param r
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addcircle(double x, double y, double r, std::string color) {
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r", r)
            << attrib("fill", "white")
            << attrib("fill-opacity", 0.4)
            << attrib("stroke-width", 1)
            << attrib("stroke-dasharray", 10, 5)
            << attrib("stroke", color)

            << "/>\n";
}

/*!
 * \fn addLine
 * \brief Ajouter une ligne
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color) {
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("class", "arete")
            << attrib("stroke", color)
            << "/>\n";
}

/*!
 * \fn addLine
 * \brief Ajouter une ligne
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param color
 * @param clas
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color ,std::string clas) {
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("class", clas)
            << attrib("stroke", color)
            << "/>\n";
}

/*!
 * \fn addCross
 * \brief Ajouter une croix
 * @param x
 * @param y
 * @param span
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addCross(double x, double y, double span, std::string color) {
    addLine(x - span, y - span, x + span, y + span, color);
    addLine(x - span, y + span, x + span, y - span, color);
}

/*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param text
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addpoint(double x, double y, std::string color ) {
    m_ostrm << "<line "
            << attrib("class", "point ")
            << attrib("x1", x)
            << attrib("y1", y)
            << attrib("x2",x)
            << attrib( "y2",y)
            << attrib("stroke", color)
            << attrib("class","point")
            <<"/>\n";
}

/*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param text
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addText(double x, double y, std::string text, std::string color) {
    /// <text x="180" y="60">Un texte</text>
    m_ostrm << "<text "
            << attrib("class", "effet ")
            << attrib("x", x)
            << attrib("y", y)
            << attrib("opacity","0")
            << attrib("fill", color)
            << "transform=\"translate(" << -5 << "," << 5 << ")\""
            << ">" << text << "</text>\n";
}

/*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param text
 * @param nb
 * @param color
 * @param clas
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addText(double x, double y, std::string text,int nb ,std::string color ,std::string clas) {
    /// <text x="180" y="60">Un texte</text>
    int nbcarac;
    if (nb < 10)
    {
        nbcarac =1;
    }
    else
    {
        nbcarac=2;
    }
    m_ostrm << "<text "
            << attrib("class", clas)
            << attrib("x", x)
            << attrib("y", y)
            << attrib("opacity","0")
            << attrib("fill", color)
            << "transform=\"translate(" << -5*nbcarac -2<< "," << 8 << ")\""
            << ">" << text << "</text>\n";
}

/*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param text
 * @param color
 * @param clas
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addText(double x, double y, std::string text,std::string color ,std::string clas) {
    /// <text x="180" y="60">Un texte</text>
    m_ostrm << "<text "
            << attrib("class", clas)
            << attrib("x", x)
            << attrib("y", y)
            << attrib("opacity","0")
            << attrib("fill", color)
            << "transform=\"translate(" << -5 << "," << 5 << ")\""
            << ">" << text << "</text>\n";
}

/*!
 * \fn addText
 * \brief Ajouter un texte
 * @param x
 * @param y
 * @param val
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addText(double x, double y, double val,std::string color) {
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color);
}

/*!
 * \fn addGrid
 * \brief Ajouter une grille
 * @param span
 * @param numbering
 * @param color
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addGrid(double span, bool numbering, std::string color) {
    double y = 0;
    while (y <= m_height) {
        addLine(0, y, m_width, y, color);
        addText(5, y - 5, y, color);
        y += span;
    }

    double x = 0;
    while (x <= m_width) {
        addLine(x, 0, x, m_height, color);
        addText(x + 5, 15, x, color);
        x += span;
    }
}

/*!
 * \fn makeRVB
 * \brief Fabriquer une couleur avec RVB
 * @param r
 * @param g
 * @param b
 * \return string
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
std::string makeRGB(int r, int g, int b) {
    std::ostringstream oss;
    oss << "rgb(" << r << "," << g << "," << b << ")";
    return oss.str();
}

/*!
 * \fn addrepere
 * \brief Dessiner un repère
 * @param x
 * @param y
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addrepere(int x , int y )
{
    m_ostrm << "<line "
            << attrib("x1" , x)
            << attrib("y1" ,y)
            << attrib("x2" , "2000")
            << attrib("y2", y )
            << attrib("stroke","black")
            << "/>"
            << "<line "
            << attrib("x1" , x)
            << attrib("y1" ,y)
            << attrib("x2" , x)
            << attrib("y2", "0" )
            << attrib("stroke","black")
            << "/>";
}

/*!
 * \fn fillBallColor
 * \brief
 * @param col
 * \return string
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
std::string fillBallColor(std::string col) {
    if (col.size() > 4 && col.substr(col.size() - 4) == "ball")
        col = "url(#" + col + ")";

    return col;
}

/*!
 * \fn translate
 * \brief
 * @param scale
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::transalte(int scaleX ,int scaleY)
{
    m_ostrm << "<g transform=\"translate("<<scaleX<<","<<scaleY<<")\" > \n";
}

/*!
 * \fn addA
 * \brief
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addA()
{
    m_ostrm << "<a>\n";
}

/*!
 * \fn finG
 * \brief
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::finG()
{
    m_ostrm << "</g>\n";
}


/*!
 * \fn finA
 * \brief
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::finA()
{
    m_ostrm << "</a>\n";
}

/*!
 * \fn addG
 * \brief
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addG()
{
    m_ostrm << "<g>";
}

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
 * \author BRIONNE Mathis
 * \version 0.1
 * \date
 */
void Svgfile::addencadrer(int maxX ,int minX,int maxY,int minY,int scaleX,int scaleY, std::string text)
{
    transalte(scaleX,scaleY);
    addLine(minX-25,minY-25,maxX+25, minY-25,"black","areteV");
    addLine(maxX+25, minY-25,maxX+25, maxY+25,"black","areteV");
    addLine(maxX+25, maxY+25,minX-25, maxY+25,"black","areteV");
    addLine(minX-25, maxY+25,minX-25,minY-25,"black","areteV");
    addText(minX-25,minY-35,text,"black","effetV");
    finG();
};

/// Effets "Boule en relief"
/// Horrible bricolage : ces données devraient soit être dans un fichier auxiliaire
/// ( c'était l'approche initiale qui marchait bien sur Firefox mais pas sur les autres )
/// soit générées dynamiquement en fonction des besoins (couleurs paramétrables...)
/// On fera mieux l'an prochain !
extern const std::string svgBallGradients =
        " </svg>"
        "<style> \n"
        ".point{\n"
        " stroke-width: 10;\n"
        "stroke-linecap: round;\n"
        "stroke-color : red; \n"
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        "stroke-opacity : 1; \n"
        " \n"
        " }\n"
        "g:hover .point{\n"
        " stroke-width: 10;\n"
        "stroke-linecap: round;\n"
        "stroke-color : red; \n"
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        " \n"
        " }\n"
        ".arete{\n"
        "stroke-width: 2;\n"
        "        stroke-linecap: round;\n"
        "cursor: crosshair;\n"
        " \n"
        " }\n"
        " .areteV{\n"
        "stroke-width: 2;\n"
        "        stroke-linecap: round;\n"
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        " \n"
        " }\n"
        " g:hover areteV:hover{\n"
        "stroke-width: 5;\n"
        "        stroke-linecap: round;\n"
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        " \n"
        " }\n"
        "g:hover  .areteV{\n"
        "stroke-width: 5;\n"
        "        stroke-linecap: round;\n"
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        " \n"
        " }\n"
        " .circleV {\n"
        "        stroke-width: 30;\n"
        "        stroke-linecap: round;\n"
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        "    }\n"
        ".circle {\n"
        "        stroke-width: 30;\n"
        "        stroke-linecap: round;\n"
        "cursor: crosshair;\n"
        "stroke-opacity : 0; \n"
        "    }\n"
        "a:hover .circle {\n"
        "stroke-width: 30;\n"
        "stroke-opacity : 1; \n"
        "cursor: crosshair;\n"
        "    }\n"
        "    g:hover .circleV {\n"
        "stroke-width: 40;\n"
        "stroke-opacity : 0.4; \n"
        "cursor: crosshair;\n"
        "    }\n"
        ".effetV{\n"
        "opacity: 1; \n"
        "font-size :25px;\n"
        "stroke-color : black; cursor: crosshair;\n"
        "}\n"
        ".effet{\n"
        "opacity: 0; \n"
        "font-size :25px;\n"
        "stroke-color : black; cursor: crosshair;\n"
        "}\n"
        "a:hover .effet{\n"
        "opacity: 1; \n"
        "transition: .2s;\n"
        "font-size :25px;\n"
        "stroke-color : black; cursor: crosshair;\n"
        "}\n"
        "g:hover .effetV{\n"
        "opacity: 1; \n"
        "transition: .2s;\n"
        "font-size :25px;\n"
        "stroke-color : red; cursor: crosshair;\n"
        "}\n"
        ".arete{\n"
        "stroke-width: 2;\n"
        "stroke-linecap: round;\n"
        "cursor: crosshair;\n"
        "stroke-opacity : 0; \n"
        " \n"
        " }\n"
        "a:hover  .arete{\n"
        " stroke-opacity : 1; \n"
        " }"
        "</style>\n";


