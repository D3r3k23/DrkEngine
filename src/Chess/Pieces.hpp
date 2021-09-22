#ifndef DRK_ENGINE_PIECES_HPP
#define DRK_ENGINE_PIECES_HPP

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
    };


    class Queen : public Piece
    {
    public:
        Queen(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;
    };


    class Rook : public Piece
    {
    public:
        Rook(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;
    };


    class Bishop : public Piece
    {
    public:
        Bishop(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;
    };


    class Knight : public Piece
    {
    public:
        Knight(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;
    };


    class Pawn : public Piece
    {
    public:
        Pawn(Square square, Color color);
        std::vector<Move> get_moves(const Position& position) const override;

        Rank forward_rank(int distance) const;

    private:
        // Checks if the move is a legal en passant
        bool check_en_passant(const Position& position, Square square) const;

        bool is_promotion(const Position& position, Move move) const;

        static std::vector<Move> add_promotion_moves(std::vector<Move>& moves);
    };
}

#endif // DRK_ENGINE_PIECES_HPP
