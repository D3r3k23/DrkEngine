
#include "Util.hpp"


#include <cstdlib>
#include <ctime>


namespace DrkEngine::Util
{
    ////////// Random //////////

    void Random::seed(void)
    {
        std::srand(time(NULL));
    }

    int Random::int_in_range(int lower, int upper)
    {
        return (std::rand() % (upper - lower)) - lower;
    }

    ////////////////////////////

    bool in_bounds(int rank, int file)
    {
        return (0 <= rank && rank <= 7)
            && (0 <= file && file <= 7);
    }

    template<typename T>
    bool in_range(T x, T min, T max)
    {
        return (min <= x) && (x <= max);
    }

    void print_board(const Chess::Board& board)
    {
        for (int i = 1; i <= 17; i++)
            print_board_row(board, i);
    }

    void print_board_row(const Chess::Board& board, int row)
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
}
