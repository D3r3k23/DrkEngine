
#ifndef PIECE_HPP
#define PIECE_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"

#include <vector>


namespace Drk::Chess
{
    class Position;

    class Piece // Base class
    {
    public:
        static Ptr<Piece> create(PieceEnum piece, Square square={ Rank::R1, File::Fa }, Color color=Color::None);
        Piece(void) = delete;
        virtual ~Piece(void) = default;

        virtual Ptr<std::vector<Move>> get_possible_moves(void) const = 0;

        Square    get_square    (void) const { return m_square; }
        Color     get_color     (void) const { return m_color; }
        char      get_symbol    (void) const { return to_char(m_piece); }
        PieceEnum get_piece_enum(void) const { return m_piece; }

    protected:
        Piece(PieceEnum piece, Square square, Color color, int value);

        bool check_rook_move  (int rank, int file) const;
        bool check_bishop_move(int rank, int file) const;

    protected:
        PieceEnum m_piece;
        Square m_square;
        Color m_color;
        int m_value;
    };
}


#endif // PIECE_HPP
