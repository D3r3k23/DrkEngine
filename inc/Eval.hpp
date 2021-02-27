
#ifndef EVAL_HPP
#define EVAL_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"
#include "Pieces.hpp"
#include "Position.hpp"
#include "Engine.hpp"
#include "EvalPosition.hpp"


namespace Drk::Engine
{
    class Eval
    {
    public:
        Eval(int level)
            : level(level)
        { }

        void load_position(const Chess::Position& position);
        
        Ptr<std::vector<Chess::Move>> evaluate(const Chess::Position& position);

    private:
        int level;

        Chess::Position position;
        // const EvalParams params;
        EvalWeights weights;
    };
}


#endif // EVAL_HPP
