
#ifndef BOARD_HPP
#define BOARD_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Pieces.hpp"


namespace Drk::Chess
{
    class Board
    {
    public:
        Board(void);


        // Iterators


        Ptr<Piece> get_piece(Rank rank, File file) const;

        friend class Position;

    private:
        Ptr<Piece> board[8][8];
    };
}


#endif // BOARD_HPP
