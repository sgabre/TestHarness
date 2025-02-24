#include <unity.h>

#include <Shell.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Shell_Commands_1(void)
{
    //Protocol_Commands();
    TEST_ASSERT_EQUAL_HEX8(40, 41);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_Shell_Commands_1);

    return UNITY_END();
}
