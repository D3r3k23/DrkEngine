
#ifndef EVAL_H
#define EVAL_H


#include "Core.h"
#include "ChessPrimitives.h"
#include "Position.h"


namespace Drk::Engine
{
    struct EvalWeights
    {
        double bishop;
        double rook;
        
        void set_opening(void);
        void set_middlegame(void);
        void set_endgame(void);
    };
    
    
    class Eval
    {
    public:
        void load_position(const Position& position);
        
        Ptr<std::vector<Chess::Move>> evaluate(const Chess::Position& position);

    private:
        Position position;
        EvalWeights weights;
    };
}


#endif // EVAL_H
