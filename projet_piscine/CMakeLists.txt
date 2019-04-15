cmake_minimum_required(VERSION 3.13)
project(projet_piscine)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_piscine main.cpp Graph.cpp Graph.h Sommet.cpp Sommet.h Arete.cpp Arete.h Coords.cpp Coords.h kruskal.cpp)
