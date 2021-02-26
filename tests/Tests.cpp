
#include "Tests.hpp"

using namespace Drk;
using namespace Drk::Chess;


namespace DrkTest
{
    bool test_1()
    {
        for (int i = 0; i < 20000; i++);
        DRK_LOG(INFO, "Log works properly.");
        return true;
    }

    bool rank_enum()
    {
        Rank r = R1;
        std::cout << (int)r << std::endl;
        r++;
        std::cout << (int)r << std::endl;
        return true;
    }

    bool test_2()
    {
        int X = 6, Y = 9;
        DRK_ASSERT(X != Y, "Assert suceeded.");
        return false;
    }
}
