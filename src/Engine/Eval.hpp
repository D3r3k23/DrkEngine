#ifndef DRK_ENGINE_EVAL_HPP
#define DRK_ENGINE_EVAL_HPP

#include "Core.hpp"
#include "Chess/ChessPrimitives.hpp"

#include <vector>

namespace Drk::Eval
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

#endif // DRK_ENGINE_EVAL_HPP
