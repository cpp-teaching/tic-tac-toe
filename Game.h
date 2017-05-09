#ifndef GAME_H
#define GAME_H

#include "GameStatus.h"
#include "Tile.h"
#include <vector>
#include "Grid.h"





class Game
{
    public:
        Game(int w, int h):
        m_game_grid(w, h), m_status(GameStatus::Ongoing)
        {}

        Game():
        m_game_grid(3, 3), m_status(GameStatus::Ongoing)
        {}



        //make this function and its similars able to determine what sign they're checking for (for specific x or o victories)
        bool check_singlex_vertical(int x, int y)
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

        bool check_wholex_vertical()
        {
            for( int x = 0; x < m_game_grid.get_width(); x = x + 1 )
                {
                if (m_game_grid.get_height()> 3)
                    {
                    for(int y = 0; y < m_game_grid.get_height() - 3; y = y + 1)
                        {

                            if (check_singlex_vertical(x,y))
                            {
                                return true;
                            }
                        }
                    }

                return check_singlex_vertical(x,0);
                }
        }

        bool check_singley_horizontal(int x, int y)
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


        bool check_wholey_horizontal()
        {
            for( int y = 0; y < m_game_grid.get_height(); y = y + 1 )
                {
                if (m_game_grid.get_width()> 3)
                    {
                    for(int x = 0; x < m_game_grid.get_width() - 3; x = x + 1)
                        {

                            if (check_singley_horizontal(x,y))
                            {
                                return true;
                            }
                        }
                    }

                return check_singley_horizontal(0,y);
                }
        }

        bool check_diagonal_left(int x, int y)
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
        bool check_diagonal_right(int x, int y)
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

        bool check_diagonal()
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
                                return check_diagonal_left(x,y);
                            }
                        }
                    return check_diagonal_left(x,0);
                    }





                //checks right
                for( int x = m_game_grid.get_width(); x > 3; x = x - 1 )
                {

                    if (m_game_grid.get_height()> 3)
                        {
                        for(int y = 0; y < m_game_grid.get_height() - 3; y = y + 1)
                            {
                                return check_diagonal_right(x,y);
                            }
                        }
                    return check_diagonal_right(x,0);
                }
             }
            if (check_diagonal_left(0,0) == true)
            {
                return true;
            }
            if (check_diagonal_right(3,0) == true)
            {
                return true;
            }
            else{
                return false;
            }
        }



        void check_game_status()
        {
            if (check_diagonal() || check_wholex_vertical() || check_wholey_horizontal())
            {
                m_status = GameStatus::End;
            }
        }


    private:
    Grid m_game_grid;
    GameStatus m_status;



};

#endif // GAME_H
