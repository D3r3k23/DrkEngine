
/*////////////////////////////////////
 * Chess piece base class. Derived
 * classes defined in Pieces.hpp
/*////////////////////////////////////

#ifndef PIECE_HPP
#define PIECE_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"

#include <vector>


namespace Drk::Chess
{
    class Position; // Forward declaration

    class Piece // Base class
    {
    public:
        static Ptr<Piece> create(PieceEnum piece, Square square={ Rank::R1, File::Fa }, Color color=Color::None);
        Piece(void) = delete;
        virtual ~Piece(void) = default;

        // Gets all legal moves for the piece
        virtual std::vector<Move> get_moves(const Position& position) const = 0;

        Square    get_square    (void) const { return m_square; }
        Color     get_color     (void) const { return m_color; }
        char      get_symbol    (void) const { return to_char(m_piece); }
        PieceEnum get_piece_enum(void) const { return m_piece; }

    protected:
        Piece(PieceEnum piece, Square square, Color color, int value);

        // Used by get_moves() overrides
        // Gets the possible moves for the piece, not taking into account
          // non-eliminated checks, castling
        virtual std::vector<Move> get_possible_moves(const Position& position) const;

        // Checks if the square is a potential move (in-bounds, not the same square)
        // distance: max distance from current square
        bool check_rook_move  (const Position& position, Square square, int distance=8) const; // Horizontal & vertical moves
        bool check_bishop_move(const Position& position, Square square, int distance=8) const; // Diagonal moves
        bool check_queen_move (const Position& position, Square square, int distance=8) const; // Any direction
        bool check_knight_move(const Position& position, Square square) const;
        bool check_pawn_move  (const Position& position, Square square) const;

        // Checks if the move is a legal capture (if move is not a capture at all, still returns false)
        bool check_legal_capture(const Position& position, Square square) const;

        // Checks if the move destination is not the source
        bool check_is_move(Square square)
            { return (square != m_square); }
        
        /////// ~~~~~Checks for not eliminating check~~~~~~
        bool check_legal_move(const Position& position, Move move);

    protected:
        PieceEnum m_piece;
        Square m_square;
        Color m_color;
        int m_value;
    };
}


#endif // PIECE_HPP
