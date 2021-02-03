
#ifndef CHESS_H
#define CHESS_H


#include "Core.h"

#include <fstream>


namespace Drk::Chess
{
    enum Rank
    {
        R1 = 0,
        R2,
        R3,
        R4,
        R5,
        R6,
        R7,
        R8
    };

    enum File
    {
        FA = 0,
        FB,
        fC,
        FD,
        FE,
        FF,
        FG,
        FH
    };

    Rank& operator++(Rank& rank);
    File& operator++(File& file);

    enum Piece : char
    {
        None   = 0,
        King   = 'K',
        Queen  = 'Q',
        Rook   = 'R',
        Bishop = 'B',
        Knight = 'N',
        Pawn   = 'P'
    };

    enum Color
    {
        White,
        Black
    };

    struct Square
    {
        Rank rank;
        File file;
        Piece piece;
    };

    class Board
    {
    public:
        Board();
        void load_position(const char* fn);

    private:

    private:
        Square board[8][8];
    };
}


#endif // CHESS_H
