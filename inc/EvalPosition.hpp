
/*//////////////////////////////////////////////////
 * Chess:Position wrapper class for use by Eval
 * Contains evalution data
/*//////////////////////////////////////////////////

#ifndef EVAL_POSITION_HPP
#define EVAL_POSITION_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Position.hpp"


namespace Drk::Engine
{
    class EvalPosition
    {
    public:
        EvalPosition();

    private:
        Chess::Position m_position;

        int eval;
    };
}

#endif // EVAL_POSITION_HPP
