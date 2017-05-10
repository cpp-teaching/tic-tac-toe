#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include"Tile.h"
#include"Grid.h"



class SearchEngine
{
    public:
        bool check_singlex_vertical(int x, int y, Grid m_game_grid)
        {
            if (m_game_grid.get_tile(x,y) != Tile::Empty && m_game_grid.get_tile(x,y) == m_game_grid.get_tile(x,y+1) && m_game_grid.get_tile(x,y+1) == m_game_grid.get_tile(x,y+2))
                {
                return true;
                }
                else
                    {
                    return false;
                    }
        }

        bool check_wholex_vertical(Grid m_game_grid)
        {
            for( int x = 0; x < m_game_grid.get_width(); x = x + 1 )
                {
                if (m_game_grid.get_height()> 3)
                    {
                    for(int y = 0; y < m_game_grid.get_height() - 3; y = y + 1)
                        {

                            if (check_singlex_vertical(x,y, m_game_grid))
                            {
                                return true;
                            }
                        }
                    }

                return check_singlex_vertical(x,0, m_game_grid);
                }
        }

        bool check_singley_horizontal(int x, int y, Grid m_game_grid)
        {
            if (m_game_grid.get_tile(x,y) != Tile::Empty && m_game_grid.get_tile(x,y) == m_game_grid.get_tile(x+1,y) && m_game_grid.get_tile(x+1,y) == m_game_grid.get_tile(x+2,y))
                {
                return true;
                }
                else
                    {
                    return false;
                    }
        }


        bool check_wholey_horizontal(Grid m_game_grid)
        {
            for( int y = 0; y < m_game_grid.get_height(); y = y + 1 )
                {
                if (m_game_grid.get_width()> 3)
                    {
                    for(int x = 0; x < m_game_grid.get_width() - 3; x = x + 1)
                        {

                            if (check_singley_horizontal(x,y, m_game_grid))
                            {
                                return true;
                            }
                        }
                    }

                return check_singley_horizontal(0,y, m_game_grid);
                }
        }

        bool check_diagonal_left(int x, int y, Grid m_game_grid)
            {
                if (m_game_grid.get_tile(x,y) != Tile::Empty && m_game_grid.get_tile(x,y) == m_game_grid.get_tile(x+1,y+1) && m_game_grid.get_tile(x+1,y+1) == m_game_grid.get_tile(x+2,y+2))
                {
                    return true;
                }
                else
                    {
                    return false;
                    }
            }
        bool check_diagonal_right(int x, int y, Grid m_game_grid)
            {
            if (m_game_grid.get_tile(x,y) != Tile::Empty && m_game_grid.get_tile(x,y) == m_game_grid.get_tile(x-1,y+1) && m_game_grid.get_tile(x-1,y+1) == m_game_grid.get_tile(x-2,y+2))
                {
                    return true;
                }
                else
                    {
                    return false;
                    }
            }

        bool check_diagonal(Grid m_game_grid)
        {

            if (m_game_grid.get_height() > 3)
            {
                //checks left
                for( int x = 0; x < m_game_grid.get_width(); x = x + 1 )
                    {
                    if (m_game_grid.get_height()> 3)
                        {
                        for(int y = 0; y < m_game_grid.get_height() - 3; y = y + 1)
                            {
                                return check_diagonal_left(x,y, m_game_grid);
                            }
                        }
                    return check_diagonal_left(x,0, m_game_grid);
                    }





                //checks right
                for( int x = m_game_grid.get_width(); x > 3; x = x - 1 )
                {

                    if (m_game_grid.get_height()> 3)
                        {
                        for(int y = 0; y < m_game_grid.get_height() - 3; y = y + 1)
                            {
                                return check_diagonal_right(x,y, m_game_grid);
                        }
                    return check_diagonal_right(x,0, m_game_grid);
                }
             }
            if (check_diagonal_left(0,0, m_game_grid) == true)
            {
                return true;
            }
            if (check_diagonal_right(3,0, m_game_grid) == true)
            {
                return true;
            }
            else{
                return false;
            }
        }

};

#endif // SEARCHENGINE_H
