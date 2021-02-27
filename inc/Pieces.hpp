
#ifndef PIECES_HPP
#define PIECES_HPP


#include "Core.hpp"
#include "Util.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"

#include <vector>


namespace Drk::Chess::Pieces
{
    class None : public Piece
    {
    public:
        None(Square square, Color color);
        Ptr<std::vector<Move>> get_possible_moves(void) const override;
    };

    class King : public Piece
    {
    public:
        King(Square square, Color color);
        Ptr<std::vector<Move>> get_possible_moves(void) const override;

        bool has_moved(void) const { return m_hasMoved; }
    
    private:
        bool m_hasMoved = false;
    };

    class Queen : public Piece
    {
    public:
        Queen(Square square, Color color);
        Ptr<std::vector<Move>> get_possible_moves(void) const override;
    };

    class Rook : public Piece
    {
    public:
        Rook(Square square, Color color);
        Ptr<std::vector<Move>> get_possible_moves(void) const override;

        bool has_moved(void) const { return m_hasMoved; }
    
    private:
        bool m_hasMoved = false;
    };

    class Bishop : public Piece
    {
    public:
        Bishop(Square square, Color color);
        Ptr<std::vector<Move>> get_possible_moves(void) const override;
    };

    class Knight : public Piece
    {
    public:
        Knight(Square square, Color color);
        Ptr<std::vector<Move>> get_possible_moves(void) const override;
    };

    class Pawn : public Piece
    {
    public:
        Pawn(Square square, Color color);
        Ptr<std::vector<Move>> get_possible_moves(void) const override;
    };
}


#endif // PIECES_HPP
