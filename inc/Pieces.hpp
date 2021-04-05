
/*////////////////////////////////////////////////////
 * - Chess piece classes derived from Chess::Piece
 * - Main function is to override get_moves() and
 *     track piece data
/*////////////////////////////////////////////////////

#ifndef PIECES_HPP
#define PIECES_HPP


#include "ChessPrimitives.hpp"
#include "Piece.hpp"

#include <vector>


class Drk::Chess::Position; // Forward declaration

namespace Drk::Chess::Pieces
{
    class None : public Piece
    {
    public:
        None(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;
    };

    class King : public Piece
    {
    public:
        King(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;

        bool has_moved(void) const { return m_hasMoved; }

    private:
        std::vector<Move> get_possible_moves(const Position& position) const override;
    
    private:
        bool m_hasMoved = false;
    };

    class Queen : public Piece
    {
    public:
        Queen(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;

    private:
        std::vector<Move> get_possible_moves(Square square) const;
    };

    class Rook : public Piece
    {
    public:
        Rook(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;

        bool has_moved(void) const { return m_hasMoved; }

    private:
        std::vector<Move> get_possible_moves(Square square) const;
    
    private:
        bool m_hasMoved = false;
    };

    class Bishop : public Piece
    {
    public:
        Bishop(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;

    private:
        std::vector<Move> get_possible_moves(Square square) const;
    };

    class Knight : public Piece
    {
    public:
        Knight(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;

    private:
        std::vector<Move> get_possible_moves(Square square) const;
    };

    class Pawn : public Piece
    {
    public:
        Pawn(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;

        Rank forward_rank(int distance) const
            { return (m_color == Color::White) ? m_square.rank + 1 : m_square.rank - 1; }

    private:
        // Checks if the move is a legal en passant
        bool check_en_passant(const Position& position, Square square) const;

        bool is_promotion(const Position& position, Move move) const
            { return (move.to.rank == position.pawn_promotion_rank()); }

        static std::vector<Move> add_promotion_moves(std::vector<Move>& moves);
    };
}


#endif // PIECES_HPP
