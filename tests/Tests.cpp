
#include "Tests.hpp"

#include "DrkEngine.hpp"
using namespace Drk;

namespace DrkTest
{
    bool test_1()
    {
        for (int i = 0; i < 20000; i++);
        DRK_LOG(INFO, "Log works properly.");
        return true;
    }
}
