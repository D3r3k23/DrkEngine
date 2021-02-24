
#ifndef TESTS_HPP
#define TESTS_HPP


#include <iostream>
#include <functional>
#include <chrono>


#define RUN_TEST(test) DrkTest::Util::run(DrkTest::test, #test)

namespace DrkTest
{
    namespace Util
    {
        using Clock    = std::chrono::steady_clock;
        using TimePnt  = std::chrono::time_point<Clock>;
        using MicroSec = std::chrono::microseconds;

        void run(std::function<bool()> func, const char* name)
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
    
    // Test test case
    // Tests DRK_LOG
    bool test_1();
}


#endif // TESTS_HPP
