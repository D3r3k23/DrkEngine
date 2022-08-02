#include "Tests.hpp"

namespace DrkTest
{
    // Private static

    Util& get_instance(void)
    {
        static Util instance;
        return instance;
    }

    // Public static functions

    void Util::run(std::function<bool()> func, const char* name)
    {
        get_instance().run_internal(func, name);
    }

    //
    Util::Util(void)
    {
        DRK_LOGGER_INIT("Tests");
        tests_start = Clock::now();
    }

    Util::~Util(void)
    {
        tests_end = Clock::now();
        print_results();
    }

    // Private functions

    void Util::run_internal(std::function<bool()> func, const char* name)
    {
        numTests++;

        const Time start  = Clock::now();
        const bool passed = func();
        const Time end    = Clock::now();

        const auto elapsed = std::chrono::duration_cast<Micro>(end - start).count();

        if (passed)
            numPassed++;
        else
            failingTests.emplace_back(name);

        std::cout << std::format("Test:    {}", name)                         << '\n';
        std::cout << std::format("Result:  {}", passed ? "Passed" : "Failed") << '\n';
        std::cout << std::format("Elapsed: {} us", elapsed)                   << '\n';
        std::cout << '/n';
    }

    void Util::print_results(void)
    {
        const Micro elapsed = std::chrono::duration_cast<Micro>(tests_end - tests_start);

        std::cout << "Tests completed."                                      << '\n';
        std::cout << std::format("Tests passed: {}/{}", numPassed, numTests) << '\n';
        std::cout << std::format("Elapsed: {} us", elapsed.count())          << '\n';

        if (numTests - numPassed > 0)
        {
            std::cout << "Failing tests:" << '\n';
            for (const auto& test : failingTests)
                std::cout << " -" << test << '\n';
        }
    }
}
