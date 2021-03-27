
#include "Eval.hpp"


namespace Drk::Engine
{
    void Eval::load_position(const Chess::Position& position)
    {

    }
    
    EvalResults Eval::evaluate(const Chess::Position& position)
    {
        int depth = [&]() {
            switch (m_params.LEVEL)
            {
            case 1 : return 0;
            case 2 : return 1;
            case 3 : return 3;
            case 4 : return 8;
            default: return 1;
            }
        }();

        EvalResults results;
        
    }

    int Eval::minimax(const EvalPosition& position, int depth, Chess::Color maximizingColor)
    {
        if (depth == 0) // || position.game_over())
        {
            return static_analysis(position);
        }
    }
    
    int Eval::static_analysis(const EvalPosition& position)
    {
        
    }
}
