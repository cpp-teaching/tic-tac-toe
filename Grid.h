#ifndef GRID_H
#define GRID_H

#include "GameStatus.h"
#include "Tile.h"
#include <vector>
#include <iostream>




class Grid
{


public:

    Grid():
    m_data(9, Tile::Empty), m_w(3), m_h(3), field (m_w*m_h)
    {}


    Grid(std::vector <Tile> data, int w, int h):
    m_data(data), m_w(w), m_h(h), field (m_w*m_h)
    {}




    Tile& get_tile(int x, int y)
    {
        int index = x+y*m_w;

        return m_data[index];
    }

    void set_tile(int x, int y, Tile new_value)
    {
        get_tile(x,y) = new_value;
    }



    void print()
    {
        for(int a = 0; a < field; a += 1 )
    {

            if (a % 3 == 0)
                std::cout << std::endl;

            else
                std::cout << m_data[a];

    }
    }








private:
    std::vector <Tile> m_data;

    int m_w;

    int m_h;

    int field;












};












#endif // GRID_H
