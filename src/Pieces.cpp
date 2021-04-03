
#include "Pieces.hpp"
#include "Board.hpp"
#include "Position.hpp"
#include "Util.hpp"


namespace Drk::Chess::Pieces
{
    ////////// Constructors //////////

    None  ::None   (Square square, Color color) : Piece(PieceEnum::None,   square, color, 0 ) {}
    King  ::King   (Square square, Color color) : Piece(PieceEnum::King,   square, color, 99) {}
    Queen ::Queen  (Square square, Color color) : Piece(PieceEnum::Queen,  square, color, 9 ) {}
    Rook  ::Rook   (Square square, Color color) : Piece(PieceEnum::Rook,   square, color, 5 ) {}
    Bishop::Bishop (Square square, Color color) : Piece(PieceEnum::Bishop, square, color, 3 ) {}
    Knight::Knight (Square square, Color color) : Piece(PieceEnum::Knight, square, color, 3 ) {}
    Pawn  ::Pawn   (Square square, Color color) : Piece(PieceEnum::Pawn,   square, color, 1 ) {}

    ////////// get_moves() //////////

    std::vector<Move> None::get_moves(const Position& position) const
    {
        return std::vector<Move>();
    }

    std::vector<Move> King::get_moves(const Position& position) const
    {
        auto moves = get_possible_moves(position);

        for (move : moves)
        {
            Position newPosition = position;
            if (newPosition.is_in_check(m_piece))
        }
    }

    std::vector<Move> Queen::get_moves(const Position& position) const
    {
        auto moves = get_possible_moves(position);

        for (const auto& move : moves);

        return moves;
    }

    std::vector<Move> Rook::get_moves(const Position& position) const
    {
        auto moves = get_possible_moves(position);

        for (const auto& move : moves);

        return moves;
    }

    std::vector<Move> Bishop::get_moves(const Position& position) const
    {
        auto moves = get_possible_moves(position);

        for (const auto& move : moves);

        return moves;
    }

    std::vector<Move> Knight::get_moves(const Position& position) const
    {
        auto moves = get_possible_moves(position);

        for (const auto& move : moves);

        return moves;
    }

    std::vector<Move> Pawn::get_moves(const Position& position) const
    {
        std::vector<Move> moves;
        auto possible = get_possible_moves(position);

        for (const auto& move : moves);

        return moves;
    }

    ////////// get_possible_moves() //////////

    std::vector<Move> King::get_possible_moves(const Position& position) const
    {
        std::vector<Move> moves;

        for (const auto& piece : position.get_pieces())
        {
            const auto& square = piece.get_square()
            if (check_queen_move(square, 1))
            {
                Move move(m_square, square, PieceEnum::King);
                if (check_legal_move(move))
                    moves.push_back(move);
            }
        }
        return moves;
    }

    std::vector<Move> Queen::get_possible_moves(const Position& position) const
    {
        std::vector<Move> moves;

        for (const auto& piece : position.get_pieces())
        {
            const auto& square = piece.get_square();
            if (check_queen_move(square))
                moves.push_back(Move(m_square, square, PieceEnum::Queen))
        }
        return moves;
    }

    std::vector<Move> Rook::get_possible_moves(const Position& position) const
    {
        std::vector<Move> moves;

        for (const auto& piece : position.get_pieces())
        {
            const auto& square = piece.get_square();
            if (check_rook_move(square))
                moves.push_back(Move(m_square, square, PieceEnum::Rook));
        }
        return moves;
    }

    std::vector<Move> Bishop::get_possible_moves(const Position& position) const
    {
        std::vector<Move> moves;

        for (const auto& piece : position.get_pieces())
        {
            const auto& square = piece.get_square();
            if (check_bishop_move(square))
                moves.push_back(Move(m_square, square, PieceEnum::Bishop));
        }
        return moves;
    }

    std::vector<Move> Knight::get_possible_moves(const Position& position) const
    {
        std::vector<Move> moves;

        for (const auto& piece : position.get_pieces())
        {
            const auto& square = piece.get_square();
            if (check_knight_move(square))
                moves.push_back(Move(m_square, square, PieceEnum::Bishop));
        }
        return moves;
    }

    std::vector<Move> Pawn::get_possible_moves(const Position& position) const
    {
        std::vector<Move> moves;

        for (const auto& piece : position.pieces())
        {
            const auto& square = piece.get_square();
            if (check_pawn_move(square))
            {
                MoveType type;
                if (position.square_occupied(square))
                {
                    if (check_legal_capture(position, square))
                    {
                        type = MoveType::Capture;
                    }
                    else if (check_en_passant(position, square)) // Checks if the square is en-passant-able
                    {
                        type = MoveType::EnPassant;
                    }
                    else
                        break;
                }
                else
                    type = MoveType::Move;
                
                Move move(m_square, square, m_piece, type);
                
                if (square.rank == position.promotion_rank())
                    add_promotion_moves(moves, move);
                else
                {
                    moves.push_back(move);
                }
            }
        }

        return moves;
    }

    ////////// check_legal_move() //////////




    ////////// Others //////////

    bool Pawn::check_en_passant(const Position& position, Move move) const
    {
        
    }

    std::vector<Move> Pawn::add_promotion_moves(std::vector<Move>& moves, Move move)
    {
        moves.push_back(move.make_promotion(PieceEnum::Queen));
        moves.push_back(move.make_promotion(PieceEnum::Rook));
        moves.push_back(move.make_promotion(PieceEnum::Bishop));
        moves.push_back(move.make_promotion(PieceEnum::Knight));
    }
}
