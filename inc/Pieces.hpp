
#ifndef PIECES_HPP
#define PIECES_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"

#include <vector>


namespace Drk::Chess
{
    class Piece // Base class
    {
    public:
        static Ptr<Piece> create(PieceEnum piece, Square square={ R1, Fa }, Color color=Color::None);
        Piece(void) = delete;
        virtual ~Piece(void) = default;


        Color get_color(void) const { return color; }
        char get_symbol(void) const { return (char)piece; }


        virtual Ptr<std::vector<Move>> get_legal_moves(void) const = 0;

    protected:
        Piece(PieceEnum piece, Square square, Color color, int value);

        PieceEnum piece;
        Square square;
        Color color;
        int value;
    };

    namespace Pieces
    {
        class None : public Piece
        {
        public:
            None(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(void) const override;
        };

        class King : public Piece
        {
        public:
            King(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(void) const override;
        };

        class Queen : public Piece
        {
        public:
            Queen(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(void) const override;
        };

        class Rook : public Piece
        {
        public:
            Rook(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(void) const override;
        };

        class Bishop : public Piece
        {
        public:
            Bishop(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(void) const override;
        };

        class Knight : public Piece
        {
        public:
            Knight(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(void) const override;
        };

        class Pawn : public Piece
        {
        public:
            Pawn(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(void) const override;
        };

        
    }
}


#endif // PIECES_HPP
