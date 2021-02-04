
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
    class Position
    {
    public:
        Position(void);

        bool can_en_passant();

        void load(const char* fn);
        void save(const char* fp);

        
        // friend class Eval;
    
    private:

    private:
        Board board;
        Color toPlay;

        bool opening    = false;
        bool middlegame = false;
        bool endgame    = false;

        // Castling rights
        bool castleWhite = false;
        bool castleBlack = false;

        // End of game
        bool checkmate = false;
        bool stalemate = false;
        bool threefold = false;
    };
}


#endif // POSITION_H
