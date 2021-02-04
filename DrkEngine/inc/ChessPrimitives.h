
#ifndef CHESS_H
#define CHESS_H


#include "Core.h"


namespace Drk::Chess
{
    enum Rank { R1=0, R2, R3, R4, R5, R6, R7, R8 };
    enum File { Fa=0, Fb, Fc, Fd, Fe, Ff, Fg, Fh };

    Rank operator+(const Rank& rank, int n);
    Rank operator-(const Rank& rank, int n);
    File operator+(const File& file, int n);
    File operator-(const File& file, int n);

    Rank operator++(Rank& rank) { rank = rank + 1; return rank; }
    Rank operator--(Rank& rank) { rank = rank - 1; return rank; }
    File operator++(File& file) { file = file + 1; return file; }
    File operator--(File& file) { file = file - 1; return file; }

    Rank operator++(Rank& rank, int) { Rank prev = rank; rank = rank + 1; return prev; }
    Rank operator--(Rank& rank, int) { Rank prev = rank; rank = rank - 1; return prev; }
    File operator++(File& file, int) { File prev = file; file = file + 1; return prev; }
    File operator--(File& file, int) { File prev = file; file = file - 1; return prev; }


    struct Square
    {
        Rank rank;
        File file;
    };

    enum class PieceEnum : char
    {
        None   = ' ',
        King   = 'K',
        Queen  = 'Q',
        Rook   = 'R',
        Bishop = 'B',
        Knight = 'N',
        Pawn   = 'P'
    };

    enum class Color : char
    {
        None  = ' ',
        White = 'w',
        Black = 'b'
    };


    struct Move
    {
        Square from, to;
        PieceEnum piece;

        Move(Square from, Square to, PieceEnum piece)
            : from(from), to(to), piece(piece)
        {}

        std::string to_str(); // returns ex: "Nf3-g5"
    };
}


#endif // CHESS_H
