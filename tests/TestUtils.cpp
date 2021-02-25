
#include "Tests.hpp"

using namespace Drk;


namespace DrkTest
{
    using Clock    = std::chrono::steady_clock;
    using TimePnt  = std::chrono::time_point<Clock>;
    using MicroSec = std::chrono::microseconds;


    Ptr<Util> Util::instance = nullptr;
    

    // Public static members

    void Util::init(void)
    {
        DRK_LOGGER_INIT("Tests");
        instance = make_ptr<Util>();
    }

    void Util::run(std::function<bool()> func, const char* name)
    {
        if (!instance)
            init();
        
        instance->numTests++;

        TimePnt start = Clock::now();
        bool passed   = func();
        TimePnt end   = Clock::now();

        if (passed)
            instance->numPassed++;

        MicroSec elapsed = std::chrono::time_point_cast<MicroSec>(end  ).time_since_epoch()
                         - std::chrono::time_point_cast<MicroSec>(start).time_since_epoch();

        std::cout << "Test:    " << name                           << std::endl;
        std::cout << "Result:  " << (passed ? "Passed" : "Failed") << std::endl;
        std::cout << "Profile: " << elapsed.count() << " us"       << std::endl;
        std::cout << std::endl;
    }


    // Constructor & destructor

    Util::Util(void)
    {
        numTests  = 0;
        numPassed = 0;
    }

    Util::~Util(void)
    {
        std::cout << std::endl;
        std::cout << "Tests completed." << std::endl;
        std::cout << "Tests passed: " << numPassed << "/" << numTests << std::endl;
    }
}
