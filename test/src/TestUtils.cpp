#include "Tests.hpp"

#include <iostream>
#include <chrono>

namespace DrkTest
{
    // Private static instance
    Util* Util::s_instance = nullptr;


    // Public static functions

    void Util::init(void)
    {
        DRK_LOGGER_INIT("Tests");
        s_instance = new Util;
    }

    void Util::run(std::function<bool()> func, const char* name)
    {
        if (!s_instance)
            init();

        s_instance->run_internal(func, name);
    }

    // Destructor
    Util::~Util(void)
    {
        print_results();
    }

    // Private functions

    void Util::run_internal(std::function<bool()> func, const char* name)
    {
        using Clock = std::chrono::steady_clock;
        using Time  = std::chrono::time_point<Clock>;
        using Micro = std::chrono::microseconds;

        numTests++;

        const Time start  = Clock::now();
        const bool passed = func();
        const Time end    = Clock::now();

        const Micro elapsed = std::chrono::duration_cast<Micro>(end - start);

        if (passed)
            numPassed++;
        else
            failingTests.emplace_back(name);

        std::cout << "Test:    " << name                           << std::endl;
        std::cout << "Result:  " << (passed ? "Passed" : "Failed") << std::endl;
        std::cout << "Profile: " << elapsed.count() << " us"       << std::endl;
        std::cout << std::endl;
    }

    void Util::print_results(void)
    {
        std::cout << "Tests completed." << std::endl;
        std::cout << "Tests passed: " << numPassed << "/" << numTests << std::endl;

        if (numTests - numPassed > 0)
        {
            std::cout << "Failed tests:" << std::endl;
            for (const auto& test : failingTests)
                std::cout << " -" << test << std::endl;
        }
    }
}
