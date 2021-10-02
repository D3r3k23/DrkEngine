
/*//////////////////////////////
 * Various utilities
/*//////////////////////////////

#ifndef DRK_ENGINE_UTIL_HPP
#define DRK_ENGINE_UTIL_HPP


namespace DrkEngine::Util
{
    class Random
    {
        static void seed(void);
        static int int_in_range(int lower, int upper);
    };


    bool in_bounds(int rank, int file);

    template<typename T>
    bool in_range(T x, T min, T max);

    print_board(const Chess::Board& board);
    print_board_row(const Chess::Board& board, int row);
}


#endif // DRK_ENGINE_UTIL_HPP
