
/*//////////////////////////////////////
 * - DrkEngine base definitions and ...
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

    // Contains a move and its eval rating
    struct EvalMove
    {
        Chess::Move move;
        int eval;

        EvalMove(const Chess::Move& move, int eval)
            : move(move), eval(eval)
        { }
    };

    // The results of an evaluation
    struct EvalResults
    {
        std::vector<EvalMove> moves;
    };
}


#endif // ENGINE_HPP
