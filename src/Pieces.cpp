
#include "Pieces.hpp"


namespace Drk::Chess::Pieces
{
    None  ::None   (Square square, Color color) : Piece(PieceEnum::None,   square, color, 0 ) {}
    King  ::King   (Square square, Color color) : Piece(PieceEnum::King,   square, color, 99) {}
    Queen ::Queen  (Square square, Color color) : Piece(PieceEnum::Queen,  square, color, 9 ) {}
    Rook  ::Rook   (Square square, Color color) : Piece(PieceEnum::Rook,   square, color, 5 ) {}
    Bishop::Bishop (Square square, Color color) : Piece(PieceEnum::Bishop, square, color, 3 ) {}
    Knight::Knight (Square square, Color color) : Piece(PieceEnum::Knight, square, color, 3 ) {}
    Pawn  ::Pawn   (Square square, Color color) : Piece(PieceEnum::Pawn,   square, color, 1 ) {}


    Ptr<std::vector<Move>> None::get_possible_moves(void) const
    {
        return make_ptr<std::vector<Move>>();
    }

    Ptr<std::vector<Move>> King::get_possible_moves(void) const
    {
        auto moves = make_ptr<std::vector<Move>>();
        const int kRank = to_index(m_square.rank);
        const int kFile = to_index(m_square.file);

        for (int r = kRank - 1; r <= kRank + 1; r++)
            for (int f = kFile - 1; f <= kFile + 1; f++)
                if (Util::in_bounds(r, f))
                {
                    const Square square(r, f);
                    if (square != m_square)
                        moves->push_back(Move(m_square, square, PieceEnum::King));
                }
        return moves;
    }

    Ptr<std::vector<Move>> Queen::get_possible_moves(void) const
    {
        auto moves = make_ptr<std::vector<Move>>();

        for (int r = 0; r < 8; r++)
            for (int f = 0; f < 8; f++)
                if (Util::in_bounds(r, f))
                    if (check_rook_move(r, f) || check_bishop_move(r, f))
                        moves->push_back(Move(m_square, Square(r, f), PieceEnum::King));
        return moves;
    }

    Ptr<std::vector<Move>> Rook::get_possible_moves(void) const
    {
        auto moves = make_ptr<std::vector<Move>>();

        for (int r = 0; r < 8; r++)
            for (int f = 0; f < 8; f++)
                if (Util::in_bounds(r, f))
                    if (check_rook_move(r, f))
                        moves->push_back(Move(m_square, Square(r, f), PieceEnum::King));
        return moves;
    }

    Ptr<std::vector<Move>> Bishop::get_possible_moves(void) const
    {
        auto moves = make_ptr<std::vector<Move>>();

        for (int r = 0; r < 8; r++)
            for (int f = 0; f < 8; f++)
                if (Util::in_bounds(r, f))
                    if (check_bishop_move(r, f))
                        moves->push_back(Move(m_square, Square(r, f), PieceEnum::King));
        return moves;
    }

    Ptr<std::vector<Move>> Knight::get_possible_moves(void) const
    {
        auto moves = make_ptr<std::vector<Move>>();


        return moves;
    }

    Ptr<std::vector<Move>> Pawn::get_possible_moves(void) const
    {
        auto moves = make_ptr<std::vector<Move>>();

        const int r = to_index(m_square.rank) + 1;
        for (int f = to_index(m_square.file) - 1; f <= to_index(m_square.file) + 1; f++)
            if (Util::in_bounds(r, f))
                moves->push_back(Move(m_square, Square(r, f), PieceEnum::Pawn));

        if (m_square.rank == Rank::R2)
            moves->push_back(Move(m_square, Square(m_square.rank + 2, m_square.file), PieceEnum::Pawn));

        return moves;
    }
}
