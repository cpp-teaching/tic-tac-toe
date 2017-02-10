#ifndef TILE_H
#define TILE_H
#include <vector>
#include <iostream>

enum class Tile
{
   Empty,
   X,
   O
};


  std::ostream operator <<(std::ostream& stream, const Tile& tile)  {
    switch(tile) {
        case Tile::X:
            stream << "|X|";
            break;
        case Tile::O:
            stream << "|O|";
            break;
        case Tile::Empty:
            stream << "|-|";
            break;
    }
    return stream;
    }


#endif // TILE_H
