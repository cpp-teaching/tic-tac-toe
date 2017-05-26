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


    Grid(int w, int h):
    m_w(w), m_h(h), field (m_w*m_h), m_data(field, Tile::Empty)
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


    int get_width()
    {
        return m_w;
    }

    int get_height()
    {
        return m_h;
    }



    void print()
    {
        for(int a = 1; a < field+1; a += 1 )
    {

            if (a % 3 == 0 && a != 0)
                std::cout << m_data[a-1] << std::endl;

            else
                std::cout << m_data[a-1];

    }
    }








private:
    std::vector <Tile> m_data;

    int m_w;

    int m_h;

    int field;












};












#endif // GRID_H
