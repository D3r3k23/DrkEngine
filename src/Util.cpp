
#include "Util.hpp"


namespace Drk::Util
{
    bool in_bounds(int rank, int file)
    {
        return (0 <= rank && rank <= 7)
            && (0 <= file && file <= 7);
    }
}
