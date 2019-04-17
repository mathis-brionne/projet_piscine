#include "Svgfile.h"
#include <iostream>
#include <sstream>

const std::string svgHeader =
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
        "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"  xmlns:xlink=\"http://www.w3.org/1999/xlink\" ";

/// Effets "Boule en relief", voir données à la fin de ce fichier
extern const std::string svgBallGradients;

std::set<std::string> Svgfile::s_openfiles;

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

Svgfile::~Svgfile() {
    // Writing the gradients into the SVG file
    m_ostrm << svgBallGradients;

    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);
    // No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
template<typename T>
std::string attrib(std::string name, T val) {
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}

std::string attrib(std::string name, std::string commande) {
    std::ostringstream oss;
    oss << name << "=\"" << commande << "\" ";
    return oss.str();
}

std::string attrib(std::string name, std::string champs ,double champs2) {
    std::ostringstream oss;
    oss << name << "=\"" << champs<<champs2 << "\" ";
    return oss.str();
}

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

std::string attrib(std::string name, std::string champs, std::string nom, std::string champs2) {
    std::ostringstream oss;
    oss << name << "=\"" << champs << champs2 << nom << "\" ";
    return oss.str();
}

std::string attrib(std::string name, std::string nom, std::string champs) {
    std::ostringstream oss;
    oss << name << "=\"" << champs << nom << "\" ";
    return oss.str();
}

std::string attrib(std::string name, std::string champs, double x, double y, std::string champs2) {
    std::ostringstream oss;
    oss << name << "=\"" << champs << -x << "," << -y << champs2 << "\"";
    return oss.str();
}

std::string attrib(std::string name, int scaleN, int scaleB) {
    std::ostringstream oss;
    oss << name << "=\"" << scaleN << "," << scaleB << "\" ";
    return oss.str();
}

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

void Svgfile::addCross(double x, double y, double span, std::string color) {
    addLine(x - span, y - span, x + span, y + span, color);
    addLine(x - span, y + span, x + span, y - span, color);
}
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

void Svgfile::addText(double x, double y, double val,std::string color) {
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color);
}

void Svgfile::addText(double x, double y, double val,std::string color ,std::string clas) {
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color ,clas );
}

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

std::string makeRGB(int r, int g, int b) {
    std::ostringstream oss;
    oss << "rgb(" << r << "," << g << "," << b << ")";
    return oss.str();
}

std::string fillBallColor(std::string col) {
    if (col.size() > 4 && col.substr(col.size() - 4) == "ball")
        col = "url(#" + col + ")";

    return col;
}
void Svgfile::transalte(int scaleX ,int scaleY)
{
    m_ostrm << "<g transform=\"translate("<<scaleX<<","<<scaleY<<")\" > \n";
}
void Svgfile::addA()
{
    m_ostrm << "<a>\n";
}
void Svgfile::finG()
{
    m_ostrm << "</g>\n";
}
void Svgfile::finA()
{
    m_ostrm << "</a>\n";
}
void Svgfile::addG()
{
    m_ostrm << "<g>";
}


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
        "transition: .2s;\n"
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
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        "stroke-opacity : 0; \n"
        "    }\n"
        "a:hover .circle {\n"
        "stroke-width: 40;\n"
        "stroke-opacity : 0.4; \n"
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
        "transition: .2s;\n"
        "cursor: crosshair;\n"
        "stroke-opacity : 0; \n"
        " \n"
        " }\n"
        "a:hover  .arete{\n"
        " stroke-opacity : 1; \n"
        " }"
        "<style>\n";


