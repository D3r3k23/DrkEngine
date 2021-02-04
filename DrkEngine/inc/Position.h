
#ifndef POSITION_H
#define POSITION_H


#include "Core.h"
#include "Chess.h"

#include <vector>


namespace Drk
{
    class Position
    {
    public:
        Position();
        Ptr<std::vector<Chess::Move>> get_legal_moves(Rank rank, File file);


    private:
        Chess::Board board;
        Chess::Color toPlay;
    };
}


#endif // POSITION_H
