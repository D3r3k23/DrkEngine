
#ifndef UTIL_HPP
#define UTIL_HPP


#include <cstdlib>
#include <ctime>


namespace Drk::Util
{
    class Random
    {
        static void init(void);
        static int get_in_range(int lower, int upper);
    };


    bool in_bounds(int rank, int file);
}


#endif // UTIL_HPP