
#include "Eval.hpp"


namespace Drk::Engine
{
    void Eval::load_position(const Chess::Position& position)
    {

    }
    
    EvalResults Eval::evaluate(const Chess::Position& position)
    {
        int depth;

        switch (m_params.LEVEL)
        {
        case 1 : depth = 0; break;
        case 2 : depth = 1; break;
        case 3 : depth = 3; break;
        case 4 : depth = 8; break;
        default: depth = 0; break;
        }

        EvalResults results;
        
    }

    int Eval::minimax(const EvalPosition& position, int depth, Chess::Color maximizingColor)
    {
        if (depth == 0) // || position.game_over())
        {
            return static_eval(position);
        }
    }
    
    int Eval::static_eval(const EvalPosition& position)
    {
        
    }
}
