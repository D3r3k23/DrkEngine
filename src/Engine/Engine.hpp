#ifndef DRK_ENGINE_ENGINE_HPP
#define DRK_ENGINE_ENGINE_HPP

#include "Core.hpp"
#include "Chess/ChessPrimitives.hpp"
#include "Eval.hpp"
#include "EvalPosition.hpp"

#include <vector>

namespace Drk::Eval
{
    class Engine
    {
    public:
        Engine(const EvalParams& params)
            : m_params(params)
        { }

        void load_position(const Chess::Position& position);

        EvalResults evaluate(const Chess::Position& position);

    private:
        int minimax(const EvalPosition& position, int depth, Chess::Color maximizingColor);
        int static_analysis(const EvalPosition& position);

    private:
        EvalPosition m_position;
        const EvalParams m_params;
        EvalWeights m_weights;
    };
}

#endif // DRK_ENGINE_ENGINE_HPP
