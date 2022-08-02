#ifndef DRK_ENGINE_EVAL_POSITION_HPP
#define DRK_ENGINE_EVAL_POSITION_HPP

#include "Core.hpp"
#include "Chess/ChessPrimitives.hpp"
#include "Chess/Position.hpp"
#include "Eval.hpp"

namespace Drk::Eval
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

#endif // DRK_ENGINE_EVAL_POSITION_HPP
