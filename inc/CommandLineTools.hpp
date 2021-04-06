
/*///////////////////////////////////////////////////////
 * - CommandLineTools: Static class that provides utilies
 *     for interacting with the command line.
 * - To use, #define DRK_EN_CL_TOOLS
 * - Developed to help ConsoleChess.
 * - Friend-er classes:
 *     Chess::Board
/*///////////////////////////////////////////////////////

#ifndef COMMAND_LINE_TOOLS_HPP
#define COMMAND_LINE_TOOLS_HPP


#include "ChessPrimitives.hpp"
#include "Piece.hpp"
#include "Board.hpp"

#include <iostream>


namespace Drk::Util
{
    #ifdef DRK_EN_CL_TOOLS

        class CommandLineTools
        {
        public:
            bool is_enabled(void)
                { return true; }
            
            static void print_board(const Chess::Board& board);
            static void print_board_row(const Chess::Board& board, int row);
            
            static void print_position(const Chess:Position& position);
        };
    
    #else

        class CommandLineTools
        {
        public:
            bool is_enabled(void)
                { return false; }
        };

    #endif // DRK_EN_CL_TOOLS


    //////// Shorthand alias ////////
    using CLTools = CommandLineTools;
}


#endif // COMMAND_LINE_TOOLS_HPP
