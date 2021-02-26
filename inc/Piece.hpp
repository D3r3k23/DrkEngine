
#ifndef PIECE_HPP
#define PIECE_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"

#include <vector>


namespace Drk::Chess
{
    class Piece // Base class
    {
    public:
        static Ptr<Piece> create(PieceEnum piece, Square square={ Rank::R1, File::Fa }, Color color=Color::None);
        Piece(void) = delete;
        virtual ~Piece(void) = default;

        virtual Ptr<std::vector<Move>> get_legal_moves(const Position& position) const = 0;

        Square get_square(void) const { return square; }
        Color get_color(void)   const { return color; }
        char get_symbol(void)   const { return to_char(piece); }
        PieceEnum get_piece_enum(void) const { return piece; }

    protected:
        Piece(PieceEnum piece, Square square, Color color, int value);

        PieceEnum piece;
        Square square;
        Color color;
        int value;
    };
}


#endif // PIECE_HPP
