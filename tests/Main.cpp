
#include "Tests.hpp"


int main(int, char**)
{   
    DRK_DEBUG_BREAK;
    INIT_TESTS();

    RUN_TEST(test_1);
    RUN_TEST(test_2);

    return 0;
}
