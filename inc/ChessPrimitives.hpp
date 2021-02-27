
#ifndef CHESS_HPP
#define CHESS_HPP


#include "Core.hpp"


namespace Drk::Chess
{
    enum class Rank : int { R1, R2, R3, R4, R5, R6, R7, R8 };
    enum class File : int { Fa, Fb, Fc, Fd, Fe, Ff, Fg, Fh };

    int to_index(Rank rank);
    int to_index(File file);
    Rank to_rank(int index);
    File to_file(int index);

    char to_char(Rank rank);
    char to_char(File file);
    Rank to_rank(char ch);
    File to_file(char ch);

    bool operator>(const Rank&, const Rank&);
    bool operator<(const File&, const File&);

    Rank operator+(const Rank&, int);
    File operator+(const File&, int);
    Rank operator-(const Rank&, int);
    File operator-(const File&, int);

    Rank& operator+=(Rank&, int);
    File& operator+=(File&, int);
    Rank& operator-=(Rank&, int);
    File& operator-=(File&, int);

    Rank& operator++(Rank&);
    File& operator++(File&);
    Rank& operator--(Rank&);
    File& operator--(File&);

    Rank operator++(Rank&, int);
    File operator++(File&, int);
    Rank operator--(Rank&, int);
    File operator--(File&, int);


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

    PieceEnum to_piece_enum(char ch);
    char to_char(PieceEnum piece);

    enum class Color : char
    {
        None  = ' ',
        White = 'w',
        Black = 'b'
    };

    Color to_color(char ch);
    char to_char(Color color);


    struct Square
    {
        Rank rank;
        File file;

        Square(Rank rank, File file)  
            : rank(rank), file(file)
        { }

        Square(int rank, int file)
            : rank(to_rank(rank)), file(to_file(file))
        { }

        std::string to_string(void)
            { return std::string(1, to_char(file)) + std::string(1, to_char(rank)); }

        bool operator==(const Square& other)
            { return (this->rank == other.rank) && (this->file == other.file); }
        
        bool operator!=(const Square& other)
            { return !(*this == other); }
    };


    struct Move
    {
        Square from, to;
        PieceEnum piece;

        Move(Square from, Square to, PieceEnum piece)
            : from(from), to(to), piece(piece)
        { }

        std::string to_string(void)
            { return to_char(piece) + from.to_string() + "-" + to.to_string(); }
    };
}


#endif // CHESS_HPP
