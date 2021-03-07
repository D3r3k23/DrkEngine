
#ifndef EVAL_POSITION_HPP
#define EVAL_POSITION_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"
#include "Pieces.hpp"
#include "Board.hpp"
#include "Position.hpp"
#include "Engine.hpp"


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
