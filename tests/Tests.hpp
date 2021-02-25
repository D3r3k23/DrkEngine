
#ifndef TESTS_HPP
#define TESTS_HPP


#include "DrkEngine.hpp"

#include <iostream>
#include <functional>
#include <chrono>


#define INIT_TESTS()   DrkTest::Util::init()
#define RUN_TEST(test) DrkTest::Util::run(DrkTest::test, #test)


namespace DrkTest
{
    class Util // Singleton
    {
    public:
        static void init(void);
        static void run(std::function<bool()> func, const char* name);

        Util(void);
        ~Util(void);
        Util(Util&) = delete;
        Util& operator=(const Util&) = delete;

    private:
        int numTests;
        int numPassed;

        static Drk::Ptr<Util> instance;
    };


    // Test test case
    // Tests DRK_LOG
    bool test_1();
}


#endif // TESTS_HPP
