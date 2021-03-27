
#include "Tests.hpp"

using namespace Drk;


namespace DrkTest
{
    std::unique_ptr<Util> Util::s_instance = nullptr;
    

    // Public static functions

    void Util::init(void)
    {
        DRK_LOGGER_INIT("Tests");
        s_instance = std::make_unique<Util>();
    }

    void Util::run(std::function<bool()> func, const char* name)
    {
        if (!s_instance)
            init();

        s_instance->run_internal(func, name);
    }


    // Private functions

    void Util::run_internal(std::function<bool()> func, const char* name)
    {
        using Clock    = std::chrono::steady_clock;
        using TimePnt  = std::chrono::time_point<Clock>;
        using MicroSec = std::chrono::microseconds;

        numTests++;

        TimePnt start = Clock::now();
        bool passed   = func();
        TimePnt end   = Clock::now();

        if (passed)
            numPassed++;
        else
            failingTests.emplace_back(name);

        MicroSec elapsed = std::chrono::time_point_cast<MicroSec>(end  ).time_since_epoch()
                         - std::chrono::time_point_cast<MicroSec>(start).time_since_epoch();

        std::cout << "Test:    " << name                           << std::endl;
        std::cout << "Result:  " << (passed ? "Passed" : "Failed") << std::endl;
        std::cout << "Profile: " << elapsed.count() << " us"       << std::endl;
        std::cout << std::endl;
    }

    void Util::print_results(void)
    {
        std::cout << "Tests completed." << std::endl;
        std::cout << "Tests passed: " << numPassed << "/" << numTests << std::endl;
        std::cout << "Failed tests:" << std::endl;
        for (const auto& test : failingTests)
            std::cout << test << std::endl;
    }


    // Constructor & destructor

    Util::Util(void)
    {
        numTests  = 0;
        numPassed = 0;
    }

    Util::~Util(void)
    {
        print_results();
    }
}
