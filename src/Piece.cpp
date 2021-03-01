
#include "Piece.hpp"
#include "Pieces.hpp"


namespace Drk::Chess
{
    Ptr<Piece> Piece::create(PieceEnum piece, Square square, Color color)
    {
        switch (piece)
        {
            case PieceEnum::King   : return make_ptr<Pieces::King>   (square, color);
            case PieceEnum::Queen  : return make_ptr<Pieces::Queen>  (square, color);
            case PieceEnum::Rook   : return make_ptr<Pieces::Rook>   (square, color);
            case PieceEnum::Bishop : return make_ptr<Pieces::Bishop> (square, color);
            case PieceEnum::Knight : return make_ptr<Pieces::Knight> (square, color);
            case PieceEnum::Pawn   : return make_ptr<Pieces::Pawn>   (square, color);
            case PieceEnum::None   : 
            default                : return make_ptr<Pieces::None>   (square, color);
        }
    }

    Piece::Piece(PieceEnum piece, Square square, Color color, int value)
        : m_piece(piece), m_square(square), m_color(color), m_value(value)
    { }

    bool Piece::check_rook_move(int rank, int file) const
    {
        return (((rank == to_index(m_square.rank)) || (file == to_index(m_square.file)))
            && (Square(rank, file) != m_square));
    }

    bool Piece::check_bishop_move(int rank, int file) const
    {
        return (((rank - to_index(m_square.rank)) == (file - to_index(m_square.file)))
            && (Square(rank, file) != m_square));
    }
}
