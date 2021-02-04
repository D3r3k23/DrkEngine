
#ifndef POSITION_H
#define POSITION_H


#include "Core.h"
#include "Chess.h"


namespace Drk
{
    class Position
    {
    public:

    private:
        Chess::Board board;
        Chess::Color toPlay;
    };
}


#endif // POSITION_H
