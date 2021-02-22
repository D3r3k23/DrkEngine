
#ifndef EVAL_HPP
#define EVAL_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
//#include "Pieces.hpp"
//#include "Position.hpp"


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
        void load_position(const Chess::Position& position);
        
        Ptr<std::vector<Chess::Move>> evaluate(const Chess::Position& position);

    private:
        Chess::Position position;
        EvalWeights weights;
    };
}


#endif // EVAL_HPP
