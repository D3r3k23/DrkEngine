
#ifndef POSITION_HPP
#define POSITION_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
//#include "Pieces.hpp"
//#include "Board.hpp"

#include <vector>
#include <fstream>


namespace Drk::Chess
{
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

        bool can_en_passant() const;

        void load_starting_position();
        
        // friend class Eval;
    
    private:
        void load_from_file(const char* fp);
        void save_to_file(const char* fp) const;

    private:
        Board board;
        Color toPlay;

        PositionFlags flags;
    };
}


#endif // POSITION_HPP
