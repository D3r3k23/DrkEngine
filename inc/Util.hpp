
/*//////////////////////////////
 * Various utilities
/*//////////////////////////////

#ifndef UTIL_HPP
#define UTIL_HPP


namespace Drk::Util
{
    class Random
    {
        static void init(void);
        static int get_in_range(int lower, int upper);
    };


    bool in_bounds(int rank, int file);

    template<typename T>
    bool in_range(T x, T min, T max)
    {
        return (min <= x) && (x <= max);
    }
}


#endif // UTIL_HPP