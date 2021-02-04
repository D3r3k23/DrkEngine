
#ifndef EVAL_H
#define EVAL_H


#include "Core.h"
#include "ChessPrimitives.h"
#include "Position.h"


namespace Drk::Engine
{
    class Eval
    {
    public:
        Ptr<std::vector<Chess::Move>> evaluate(const Chess::Position& position);

    private:
    
    };
}


#endif // EVAL_H