
#include "Board.hpp"


namespace Drk::Chess
{
    Board::Board(void)
    {
        for (int rank = 0; rank < 8; rank++)
            for (int file = 0; file < 8; file++)
                set_piece(Piece::create(PieceEnum::None, { rank, file }));
    }

    bool Board::set_piece(const Ptr<Piece>& newPiece)
    {
        int rank = to_index(newPiece->get_square().rank);
        int file = to_index(newPiece->get_square().file);
        piece(rank, file) = newPiece;
    }

    bool Board::set_piece(PieceEnum piece, Square square, Color color)
    {
        auto newPiece = Piece::create(piece, square, color);
        set_piece(newPiece);
    }

    bool Board::square_occupied(Square square) const
    {
        return get_piece(square)->get_piece_enum() != PieceEnum::None;
    }
}
