
/*////////////////////////////////////////////
 * Various chess game primitives:
 *   - Rank
 *   - File
 *   - PieceEnum
 *   - Color
 *   - Square
 *   - MoveType
 *   - Move
/*////////////////////////////////////////////

#ifndef CHESS_HPP
#define CHESS_HPP


#include "Core.hpp"


namespace Drk::Chess
{
    ////////// Rank & File //////////

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


    ////////// PieceEnum //////////

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


    ////////// Color //////////

    enum class Color : char
    {
        None  = ' ',
        White = 'w',
        Black = 'b'
    };

    Color to_color(char ch);
    char to_char(Color color);

    Color operator!(const Color& color);


    ////////// Square //////////

    struct Square
    {
        Rank rank;
        File file;

        Square(void)                 : rank(Rank::R1), file(File::Fa) { }
        Square(Rank rank, File file) : rank(rank), file(file) { }
        Square(int rank, int file)   : rank(to_rank(rank)), file(to_file(file)) { }

        std::string to_string(void)
            { return std::string(1, to_char(file)) + std::string(1, to_char(rank)); }

        bool operator==(const Square& other) const
            { return (this->rank == other.rank) && (this->file == other.file); }
        
        bool operator!=(const Square& other) const
            { return !(*this == other); }
    };


    ////////// Move //////////

    enum class MoveType
    {
        Move,
        Capture,
        EnPassant,
        CastleShort,
        CastleLong,
        Promotion
    };

    struct Move
    {
        Square from, to;
        PieceEnum piece;
        MoveType type;
        PieceEnum promoteTo;

        Move(void) = default;
        Move(const Move&) = default;

        Move(Square from, Square to, PieceEnum piece, MoveType type=MoveType::Move, PieceEnum promoteTo=PieceEnum::None)
            : from(from), to(to), piece(piece), type(type), promoteTo(promoteTo)
        { }

        Move make_promotion(PieceEnum to)
        {
            Move newMove{*this};
            newMove.type = MoveType::Promotion;
            newMove.promoteTo = to;
            return newMove;
        }

        std::string to_string(void);
    };
}


#endif // CHESS_HPP
