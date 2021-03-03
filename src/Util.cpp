
#include "Util.hpp"


namespace Drk::Util
{
    void Random::init(void)
    {
        std::srand(time(NULL));
    }

    int Random::get_in_range(int lower, int upper)
    {
        return (std::rand() % (upper - lower)) - lower;
    }

    bool in_bounds(int rank, int file)
    {
        return (0 <= rank && rank <= 7)
            && (0 <= file && file <= 7);
    }
}
