//
// Created by matbr on 15/04/2019.
//

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

    Svgfile(std::string _filename = "output.html", int _width = 2000, int _height = 2000);

    ~Svgfile();

    void addLine(double x1, double y1, double x2, double y2, std::string color = defcol);

    void addCross(double x, double y, double span, std::string color = defcol);

    void addText(double x, double y, std::string text, std::string color = defcol);

    void addText(double x, double y, double val ,std::string color);

    void addDisk(double x, double y,std::string color);

    void addlegende(double x1, double x2, double y1, double y2, std::string color, std::string text);

    void addcircle(double x, double y, double r, std::string color);

    void addSoleil(double r, std::string color);

    void addGrid(double span = 100.0, bool numbering = true, std::string color = "lightgrey");

    void addli();

    void endli();

    void transalte(int scaleX ,int scaleY);

    void finG();

    void addG();

    void addA();

    void finA();

    void addLine(double x1, double y1, double x2, double y2, std::string color ,std::string clas);

    void addText(double x, double y, std::string text,int nbcarac, std::string color, std::string clas);

    void addDisk(double x, double y, std::string color, std::string clas);

    void addText(double x, double y, double val, std::string color, std::string clas);

    void addText(double x, double y, std::string text, std::string color, std::string clas);
};

std::string makeRGB(int r, int g, int b);

std::string fillBallColor(std::string col);

#endif //PROJET_PISCINE_SVGFILE_H
