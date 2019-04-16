cmake_minimum_required(VERSION 3.13)
project(projet_piscine)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_piscine main.cpp Sommet.cpp Sommet.h Arete.cpp Arete.h Coords.cpp Coords.h kruskal.cpp Svgfile.cpp Svgfile.h menu.cpp sommes_pond.cpp Graphe.cpp Graphe.h outils.cpp outils.h)
