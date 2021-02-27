
#ifndef BOARD_HPP
#define BOARD_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"
#include "Pieces.hpp"


namespace Drk::Chess
{
    class Board
    {
    public:
        Board(void);

        const Ptr<Piece>& get_piece(int rank, int file) const
            { return board[rank][file]; }

        const Ptr<Piece>& get_piece(Rank rank, File file) const
            { return get_piece(to_index(rank), to_index(file)); }

        const Ptr<Piece>& get_piece(Square square) const
            { return get_piece(square.rank, square.file); }


        void set_piece(const Ptr<Piece>& newPiece);
        void set_piece(PieceEnum piece, Square square, Color color);

        void move_piece(Ptr<Piece> piece);

        bool square_occupied(Square square) const;

    private:
        Ptr<Piece> board[8][8];
    };
}


#endif // BOARD_HPP
