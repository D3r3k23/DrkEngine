#ifndef DRK_ENGINE_TESTS_HPP
#define DRK_ENGINE_TESTS_HPP

#include <DrkEngine/Engine.hpp>
#include <DrkEngine/Chess.hpp>

#include <iostream>
#include <format>
#include <vector>
#include <functional>
#include <chrono>

#define RUN_TEST(test) DrkTest::Util::run(DrkTest::test, #test)

namespace DrkTest
{
    using Clock = std::chrono::steady_clock;
    using Time  = std::chrono::time_point<Clock>;
    using Micro = std::chrono::microseconds;

    class Util
    {
    private:
        static Util& get_instance(void); // Singleton

    public:
        static void init(void);
        static void run(std::function<bool()> func, const char* name);

        Util(void);
        ~Util(void);

        Util(Util&) = delete;
        Util& operator=(const Util&) = delete;

    private:
        void run_internal(std::function<bool()> func, const char* name);
        void print_results(void);

    private:
        int numTests  = 0;
        int numPassed = 0;
        Time tests_start;
        Time tests_end;
        std::vector<std::string> failingTests;
    };


    // Tests DRK_LOG
    bool test_1();

    // Tests the Piece enum
    bool piece_enum();

    // Tests the Rank enum
    bool rank_enum();

    // Tests DRK_ASSERT
    bool test_assert();

    // Should fail
    bool should_fail();

    // Prints the default board to the console
    bool print_board();

    // Loads the Chess starting position from a file and prints it
    bool load_position();
}

#endif // DRK_ENGINE_TESTS_HPP
