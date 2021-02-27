
#include "Board.hpp"


namespace Drk::Chess
{
    Board::Board(void)
    {
        for (int r = 0; r < 8; r++)
            for (int f = 0; f < 8; f++)
                set_piece(Piece::create(PieceEnum::None, { r, f }));
    }

    void Board::set_piece(const Ptr<Piece>& newPiece)
    {
        int rank = to_index(newPiece->get_square().rank);
        int file = to_index(newPiece->get_square().file);
        board[rank][file] = newPiece;
    }

    void Board::set_piece(PieceEnum piece, Square square, Color color)
    {
        auto newPiece = Piece::create(piece, square, color);
        set_piece(newPiece);
    }

    bool Board::square_occupied(Square square) const
    {
        return get_piece(square)->get_piece_enum() != PieceEnum::None;
    }
}
