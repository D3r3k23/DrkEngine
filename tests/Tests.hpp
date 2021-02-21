
#ifndef TESTS_HPP
#define TESTS_HPP


#include "DrkEngine"

#include <functional>
#include <chrono>


namespace DrkTest
{
    using Time  = std::chrono::time_point<std::chrono::steady_clock>;
    using Micro = std::chrono::microseconds;

    Time now(void)
        { return std::chrono::steady_clock::now(); }


    #define RUN_TEST(test) DrkTest::run(test, #test)

    void run(std::function<bool()> func, const char* name)
    {
        std::cout << "Test: " << name << std::endl;

        Time start  = now();
        bool passed = DrkTest::func();
        Time end    = now();

        Micro elapsed = std::chromo::time_point_cast<Micro>(end  ).time_since_epoch()
                      - std::chromo::time_point_cast<Micro>(start).time_since_epoch();

        std::cout << "Result:  " << passed ? "Passed" : "Failed" << std::endl;
        std::cout << "Profile: " << elapsed << " us" << std::endl;
        std::cout << std::endl;
    }


    bool test_1()
    {
        for (int i = 0; i < 20000; i++);
        return true;
    }
}


#endif // TESTS_HPP
