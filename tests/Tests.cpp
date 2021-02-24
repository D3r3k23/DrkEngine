
#include "Tests.hpp"

#include "DrkEngine.hpp"
using namespace Drk;


namespace DrkTest
{
    namespace Util
    {
        using Clock    = std::chrono::steady_clock;
        using TimePnt  = std::chrono::time_point<Clock>;
        using MicroSec = std::chrono::microseconds;

        void run_test(std::function<bool()> func, const char* name)
        {
            TimePnt start = Clock::now();
            bool passed   = func();
            TimePnt end   = Clock::now();

            MicroSec elapsed = std::chrono::time_point_cast<MicroSec>(end  ).time_since_epoch()
                             - std::chrono::time_point_cast<MicroSec>(start).time_since_epoch();

            std::cout << "Test:    " << name                           << std::endl;
            std::cout << "Result:  " << (passed ? "Passed" : "Failed") << std::endl;
            std::cout << "Profile: " << elapsed.count() << " us"       << std::endl;
            std::cout << std::endl;
        }
    }
    
    bool test_1()
    {
        for (int i = 0; i < 20000; i++);
        DRK_LOG(INFO, "Log works properly.");
        return true;
    }
}
