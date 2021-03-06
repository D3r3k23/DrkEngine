
#ifndef EVAL_HPP
#define EVAL_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Engine.hpp"
#include "EvalPosition.hpp"

#include <vector>


namespace Drk::Engine
{
    class Eval
    {
    public:
        Eval(const EvalParams& params)
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


#endif // EVAL_HPP
