#ifndef GAME_H
#define GAME_H

#include "GameStatus.h"
#include "Tile.h"
#include <vector>
#include "Grid.h"
#include "SearchEngine.h"




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



        void check_game_status()
        {
            if (SearchEngine.check_diagonal(m_game_grid) || SearchEngine.check_wholex_vertical(m_game_grid) || SearchEngine.check_wholey_horizontal(m_game_grid))
            {
                m_status = GameStatus::End;
            }
        }



        void set_tile(int x, int y, Tile new_value)
            {
                if (m_game_grid.get_tile(x,y) == Tile::Empty)
                {
                    m_game_grid.get_tile(x,y) = new_value;
                }
            }






    private:
    Grid m_game_grid;
    GameStatus m_status;



};

#endif // GAME_H
