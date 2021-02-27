
#include "Tests.hpp"


int main(int, char**)
{   
    INIT_TESTS();

    RUN_TEST(test_1);
    RUN_TEST(piece_enum);
    RUN_TEST(rank_enum);
    RUN_TEST(test_assert);

    return 0;
}
