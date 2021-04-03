
/*//////////////////////////////////////////
 * Contains a complete chess position
/*//////////////////////////////////////////

#ifndef POSITION_HPP
#define POSITION_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"
#include "Pieces.hpp"
#include "Board.hpp"

#include <vector>


namespace Drk::Chess
{
    // Used to track in-game flags
    // - Use bitfields?
    struct PositionFlags
    {
        bool opening    = false;
        bool middlegame = false;
        bool endgame    = false;

        // Castling rights
        bool castleWhite = false;
        bool castleBlack = false;

        // End of game
        bool stalemate = false;
        bool threefold = false;
    };


    class Position
    {
    public:
        Position(void);
        std::vector<Move> get_legal_moves(void) const;

        const Piece& get_piece(Square square) const;

        bool can_en_passant(Pieces::Pawn pawn, Move move) const;

        void load_starting_position();

        bool make_move(Move move);

        bool square_occupied(Square square) const
            { return m_board.square_occupied(square); }
        
        Rank promotion_rank(void) const
            { return (m_toPlay == Color::White) ? Rank::R8 : Rank::R1; }
        
        bool can_castle(void);

        // For calling Board Iterator: for (auto piece : position.get_pieces())
        const Board& get_pieces(void)
            { return m_board; }
    
    private:
        std::vector<Move> get_player_moves(void) const;

        // Checks if the move leaves the player in check
        bool check_legal_move(Move& move) const;

        bool check_can_castle(void);

        void load_from_file(const char* fp);
        void save_to_file(const char* fp) const;

    private:
        Board m_board;
        Color m_toPlay;

        PositionFlags m_flags;

        Move m_lastMove;
    };
}


#endif // POSITION_HPP
