
#ifndef POSITION_H
#define POSITION_H


#include "Core.h"
#include "ChessPrimitives.h"
#include "Pieces.h"
#include "Board.h"

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

        void load_from_file(const char* fn);
        void save_to_file(const char* fp) const;

        
        // friend class Eval;
    
    private:

    private:
        Board board;
        Color toPlay;

        PositionFlags flags;
    };
}


#endif // POSITION_H