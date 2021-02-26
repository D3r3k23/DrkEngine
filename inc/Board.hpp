
#ifndef BOARD_HPP
#define BOARD_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"


namespace Drk::Chess
{
    class Board
    {
    public:
        Board(void);

        const Ptr<const Piece>& Board::get_piece(int rank, int file) const
            { return piece(rank, file); }

        const Ptr<const Piece>& Board::get_piece(Rank rank, File file) const
            { return get_piece(to_index(rank), to_index(file)); }

        const Ptr<const Piece>& Board::get_piece(Square square) const
            { return get_piece(square.rank, square.file); }


        bool set_piece(const Ptr<Piece>& newPiece);
        bool set_piece(PieceEnum piece, Square square, Color color);

        bool square_occupied(Square square) const;

    private:
        Ptr<Piece> board[8][8];


        Ptr<Piece>& piece(int rank, int file)
            { return board[rank][file]; }

        const Ptr<const Piece>& piece(int rank, int file) const
            { return board[rank][file]; }
    };
}


#endif // BOARD_HPP
