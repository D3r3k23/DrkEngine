
#include "CommandLineTools.hpp"


namespace Drk::Util
{
    void CLTools::print_board(const Chess::Board& board)
    {
        for (int i = 1; i <= 17; i++)
            print_board_row(board, i);
    }

    void CLTools::print_board_row(const Chess::Board& board, int row)
    {
        bool pieceRow = (row % 2 == 1); // Odd rows
        Chess::Board::Iterator_const it(board, 8 - (row / 2), 0);

        for (int i = 0; i < 8; i++)
        {
            std::cout << '|';
            if (pieceRow)
            {
                std::cout << ' ' << Chess::to_char(it->get_color()) << it->get_symbol() << ' ';
                it++;
            }
            else
                std::cout << "----";
        }
        std::cout << '|' << '\n';;
    }

    void CLTools::print_position(const Chess::Position& position)
    {
        print_board(position.m_board);
        // Other details
    }
}
