
#ifndef BOARD_H
#define BOARD_H


#include "Core.h"
#include "ChessPrimitives.h"
#include "Pieces.h"


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


#endif // BOARD_H
