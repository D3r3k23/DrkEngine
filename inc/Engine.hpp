
/*//////////////////////////////////////
 * - DrkEngine base definitions
 * - Used by Eval
 * - Contains:
 *     EvalParams
 *     EvalWeights
 *     EvalResults
/*//////////////////////////////////////

#ifndef ENGINE_HPP
#define ENGINE_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"

#include <vector>


namespace Drk::Engine
{
    // Parameters for configuring Eval (Eval accepts in constructor)
    struct EvalParams
    {
        const int LEVEL;

        EvalParams(int level)
            : LEVEL(level)
        { }
    };


    // Variables for Eval to track game state
    struct EvalWeights
    {
        double bishop;
        double rook;
        
        void set_opening(void);
        void set_middlegame(void);
        void set_endgame(void);
    };


    // The results of an evaluation:
    //   - vector of moves
    //   - rating of current position(eval of best move)
    struct EvalResults
    {
        std::vector<Chess::Move> moves;
        int eval;
    };
}


#endif // ENGINE_HPP
