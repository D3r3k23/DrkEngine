
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

    bool Piece::check_rook_move(const Position& position, Square square, int distance)
    {
        if (!check_is_move(square))
            return false;

        return (((rank == to_index(m_square.rank)) || (file == to_index(m_square.file)))
            && (Square(rank, file) != m_square));
    }

    bool Piece::check_bishop_move(const Position& position, Square square, int distance)
    {
        return (((rank - to_index(m_square.rank)) == (file - to_index(m_square.file)))
            && (Square(rank, file) != m_square));
    }

    bool Piece::check_queen_move(const Position& position, Square square, int distance)
    {
        return check_rook_move(rank, file, distance)
            || check_bishop_move(rank, file, distance);
    }

    bool Piece::check_knight_move(const Position& position, Square square)
    {

    }

    bool Piece::check_pawn_move(const Position& position, Square square)
    {
        if (check_is_move(square))
            if (Util::in_bounds(to_index(square.rank), to_index(square.file)))
            {
                if (square.rank == m_square.rank + 1)
                {
                    return Util::in_range<File>(square.file, m_square.file - 1, m_square.file + 1)
                }
                else if (square.rank == m_square.rank + 2)
                {
                    return square.file == m_square.file;
                }
            }
        return false;
    }

    bool Piece::check_legal_capture(const Position& position, Square square) const
    {
        if (position.get_piece(square).get_color() != m_color)
            return true;

        
    }
}
