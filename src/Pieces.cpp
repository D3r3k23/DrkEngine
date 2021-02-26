
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
        int kRank = to_index(square.rank);
        int kFile = to_index(square.file);

        for (int r = kRank - 1; r <= kRank + 1; r++)
            for (int f = kFile - 1; f <= kFile + 1; f++)
                if (Util::in_bounds(r, f))
                {
                    Square currentSquare(r, f);
                    if (currentSquare != square);
                        moves->push_back(Move(square, currentSquare, PieceEnum::King));
                }

        return moves;
    }

    Ptr<std::vector<Move>> Queen::get_possible_moves(void) const
    {
        return make_ptr<std::vector<Move>>();
    }

    Ptr<std::vector<Move>> Rook::get_possible_moves(void) const
    {
        return make_ptr<std::vector<Move>>();
    }

    Ptr<std::vector<Move>> Bishop::get_possible_moves(void) const
    {
        return make_ptr<std::vector<Move>>();
    }

    Ptr<std::vector<Move>> Knight::get_possible_moves(void) const
    {
        return make_ptr<std::vector<Move>>();
    }

    Ptr<std::vector<Move>> Pawn::get_possible_moves(void) const
    {
        return make_ptr<std::vector<Move>>();
    }
}
