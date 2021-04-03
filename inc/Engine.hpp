
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
#include <tuple>


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
    struct EvalMove      //////////   const auto& [move, eval] = move.data;
    {
        std::tuple<Chess::Move, int> data;

        EvalMove(const Chess::Move& move, int eval)
            : data(std::make_tuple(move, eval))
        { }

        Chess::Move get_move(void) const
            { return std::get<0>(data); }
        
        int get_eval(void) const
            { return std::get<1>(data); }
    };


    // The results of an evaluation
    struct EvalResults
    {
        std::vector<EvalMove> moves;
    };
}


#endif // ENGINE_HPP
