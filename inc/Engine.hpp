
#ifndef ENGINE_HPP
#define ENGINE_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Position.hpp"

#include <vector>


namespace Drk::Engine
{
    struct EvalParams
    {
        const int LEVEL;

        EvalParams(int level)
            : LEVEL(level)
        { }
    };


    struct EvalWeights
    {
        double bishop;
        double rook;
        
        void set_opening(void);
        void set_middlegame(void);
        void set_endgame(void);
    };


    struct EvalResults
    {
        std::vector<Ptr<Chess::Move>> moves;
        int eval;
    };
}


#endif // ENGINE_HPP
