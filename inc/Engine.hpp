
#ifndef ENGINE_HPP
#define ENGINE_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Position.hpp"


namespace Drk::Engine
{
    struct Params
    {
        const int X = 5;
    };


    struct EvalWeights
    {
        double bishop;
        double rook;
        
        void set_opening(void);
        void set_middlegame(void);
        void set_endgame(void);
    };
}


#endif // ENGINE_HPP
