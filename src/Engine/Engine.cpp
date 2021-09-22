#include "Engine.hpp"

namespace Drk::Eval
{
    void Engine::load_position(const Chess::Position& position)
    {

    }

    EvalResults Engine::evaluate(const Chess::Position& position)
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

    int Engine::minimax(const EvalPosition& position, int depth, Chess::Color maximizingColor)
    {
        if (depth == 0) // || position.game_over())
        {
            return static_analysis(position);
        }
    }

    int Engine::static_analysis(const EvalPosition& position)
    {

    }
}
