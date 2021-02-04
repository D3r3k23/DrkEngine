
#ifndef PIECES_H
#define PIECES_H


#include "Core.h"
#include "ChessPrimitives.h"

#include <vector>


namespace Drk::Chess
{
    class Piece // Base class
    {
    public:
        Piece(PieceEnum piece, Square square, Color color, int value);
        virtual ~Piece(void) = default;

        static Ptr<Piece> create(PieceEnum piece, Square square={ R1, Fa }, Color color=Color::None);

        virtual Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file);

        Color get_color(void) const { return color; }
        char get_symbol(void) const { return (char)piece; }

    protected:
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

            Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file) override;
        };

        class King : public Piece
        {
        public:
            King(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file) override;
        };

        class Queen : public Piece
        {
        public:
            Queen(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file) override;
        };

        class Rook : public Piece
        {
        public:
            Rook(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file) override;
        };

        class Bishop : public Piece
        {
        public:
            Bishop(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file) override;
        };

        class Knight : public Piece
        {
        public:
            Knight(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file) override;
        };

        class Pawn : public Piece
        {
        public:
            Pawn(Square square, Color color);

            Ptr<std::vector<Move>> get_legal_moves(Rank rank, File file) override;
        };

        
    }
}


#endif // PIECES_H