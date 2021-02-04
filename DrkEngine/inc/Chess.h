
#ifndef CHESS_H
#define CHESS_H


#include "Core.h"

#include <fstream>


// Defines Chess primitives
namespace Drk::Chess
{
    enum Rank { R1=0, R2, R3, R4, R5, R6, R7, R8 };
    enum File { Fa=0, Fb, Fc, Fd, Fe, Ff, Fg, Fh };

    Rank& operator++(Rank& rank);
    File& operator++(File& file);

    struct Square
    {
        Rank rank;
        File file;
    };

    enum PieceEnum : char
    {
        None   =  0,
        King   = 'K',
        Queen  = 'Q',
        Rook   = 'R',
        Bishop = 'B',
        Knight = 'N',
        Pawn   = 'P'
    };

    enum Color : char
    {
        White = 'w',
        Black = 'b'
    };

    class Piece
    {
    public:

    private:
        Square square;
        PieceEnum piece;
        Color color;
    };

    struct Move
    {
        Square from, to;
        PieceEnum piece;

        std::string string(void); // returns ex: "Nf3-g5"
    };

    class Board
    {
    public:
        Board();
        void load(const char* fn);

    private:

    private:
        Piece board[8][8];
    };
}


#endif // CHESS_H
