
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
        void run(std::function<bool()> func, const char* name);
    }
    
    // Test test case
    // Tests DRK_LOG
    bool test_1();
}


#endif // TESTS_HPP
