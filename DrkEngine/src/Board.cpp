
#include "Board.h"


namespace Drk::Chess
{
    Board::Board(void)
    {
        for (Rank rank = R1; rank <= R8; rank++) // Use iterators
            for (File file = Fa; file <= Fh; file++)
                board[rank][file] = Piece::create(PieceEnum::None, Square{ rank, file });
    }

    Ptr<Piece> Board::get_piece(Rank rank, File file) const
    {
        return board[rank][file];
    }
}
