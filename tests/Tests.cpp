
#include "Tests.hpp"

using namespace Drk;


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
        using namespace Chess;

        Rank r = Rank::R1;
        std::cout << to_index(r) << std::endl;
        r++;
        std::cout << to_index(r) << std::endl;
        return true;
    }

    bool piece_enum()
    {
        using namespace Chess;
        PieceEnum p = PieceEnum::King;
        std::cout << (char)p << std::endl;

        return true;
    }

    bool test_assert()
    {
        int X = 6, Y = 9;
        DRK_ASSERT(X != Y, "Assert suceeded.");
        return false;
    }
}
