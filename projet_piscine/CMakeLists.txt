cmake_minimum_required(VERSION 3.13)
project(projet_piscine)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_piscine main.cpp Graphe.cpp Graphe.h Sommet.cpp Sommet.h Arete.cpp Arete.h Coords.h kruskal.cpp Svgfile.cpp Svgfile.h Graphe.cpp outil.cpp outil.h)
