#include "Tests.hpp"

int main(int, char*[])
{
    RUN_TEST(test_1);
    RUN_TEST(piece_enum);
    RUN_TEST(rank_enum);
    RUN_TEST(should_fail);

    return 0;
}
