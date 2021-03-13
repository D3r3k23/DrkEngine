
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

        static Drk::Ptr<Util> s_instance;
    };


    // Tests DRK_LOG
    bool test_1();

    // Tests the Piece enum
    bool piece_enum();

    // Tests the Rank enum
    bool rank_enum();

    // Tests DRK_ASSERT
    bool test_assert();
}


#endif // TESTS_HPP