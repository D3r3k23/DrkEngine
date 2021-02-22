
#ifndef CHESS_HPP
#define CHESS_HPP


#include "Core.hpp"


namespace Drk::Chess
{
    enum Rank { R1=0, R2, R3, R4, R5, R6, R7, R8 };
    enum File { Fa=0, Fb, Fc, Fd, Fe, Ff, Fg, Fh };

    Rank operator+(const Rank& rank, int n);
    Rank operator-(const Rank& rank, int n);
    File operator+(const File& file, int n);
    File operator-(const File& file, int n);

    Rank& operator+=(Rank& rank, int x);
    Rank& operator-=(Rank& rank, int x);
    File& operator+=(File& file, int x);
    File& operator-=(File& file, int x);

    Rank& operator++(Rank& rank);
    Rank& operator--(Rank& rank);
    File& operator++(File& file);
    File& operator--(File& file);

    Rank operator++(Rank& rank, int);
    Rank operator--(Rank& rank, int);
    File operator++(File& file, int);
    File operator--(File& file, int);


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


#endif // CHESS_HPP
