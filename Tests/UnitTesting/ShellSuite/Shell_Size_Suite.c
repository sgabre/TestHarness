#include <unity.h>

#include <Shell.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Shell_Size_1(void)
{
    TEST_ASSERT_EQUAL_HEX8(40, 41);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_Shell_Size_1);


    return UNITY_END();
}
