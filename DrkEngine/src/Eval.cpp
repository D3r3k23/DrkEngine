
#include "Eval.hpp"


namespace Drk::Engine
{
    void EvalWeights::set_opening(void)
    {
        bishop = 1.0;
        rook = 1.0;
    }
    
    void EvalWeights::set_middlegame(void)
    {
        bishop = 1.5;
        rook = 1.0;
    }
    
    void EvalWeights::set_endgame(void)
    {
        bishop = 1.0;
        rook = 1.5;
    }
    
    
}
