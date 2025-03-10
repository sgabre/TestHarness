#include <unity.h>

#include <Module.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Module_Function_1(void)
{
    TEST_ASSERT_EQUAL_HEX8(40, Module_Function(30, 40, 50));
    TEST_ASSERT_EQUAL_HEX8(40, Module_Function(10, 70, 40));
    TEST_ASSERT_EQUAL_HEX8(33, Module_Function(33, 33, 33));
}

void test_Module_Function_2(void)
{
    TEST_ASSERT_EQUAL_HEX8(80, Module_Function(70, 80, 90));
    TEST_ASSERT_EQUAL_HEX8(127, Module_Function(127, 127, 127));
    TEST_ASSERT_EQUAL_HEX8(84, Module_Function(0, 126, 126));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_Module_Function_1);
    RUN_TEST(test_Module_Function_2);

    return UNITY_END();
}
