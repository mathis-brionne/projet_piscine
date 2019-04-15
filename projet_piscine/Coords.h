//
// Created by Charlotte Sirot on 2019-04-15.
//

#ifndef PROJET_PISCINE_COORDS_H
#define PROJET_PISCINE_COORDS_H


class Coords {
private:
    int m_x;
    int m_y;

public:
    Coords(int x, int y);
    int getX();
    int getY();

    ~Coords() = default;

};


#endif //PROJET_PISCINE_COORDS_H
