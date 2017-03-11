#include "enum.hpp"

constexpr TEST LookUpTable[] = {
    TEST_MODE_0,
    TEST_MODE_1,
    TEST_MODE_2,

    TEST_MAX,
};

constexpr bool checkEnum(TEST test) {
    return (-1 == test)
            ? true
            : LookUpTable[test] == test && checkEnum((TEST)((int)test - 1));
}

static_assert(checkEnum(TEST_MAX), "TEST enum should be synced with LookUpTable.");

int main()
{
    return 0;
}
