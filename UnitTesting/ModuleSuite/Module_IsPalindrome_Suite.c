#include <unity.h>

#include "Module.h"

// Boudery Case: INVALID_PARAM(str Pointer is NULL)
void test_Module_IsPalindrome_1(void)
{
    TEST_ASSERT_EQUAL_UINT8(false, Module_IsPalindrome(NULL) );
}

// Nominal Case: 
void test_Module_IsPalindrome_2(void)
{
    TEST_ASSERT_EQUAL_UINT8(true, Module_IsPalindrome("radar") );
}

// Nominal Case: 
void test_Module_IsPalindrome_3(void)
{
    TEST_ASSERT_EQUAL_UINT8(true, Module_IsPalindrome("Ésope reste ici et se repose") );
}

// Nominal Case: 
void test_Module_IsPalindrome_4(void)
{
    TEST_ASSERT_EQUAL_UINT8(true, Module_IsPalindrome("Hello") );
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_Module_IsPalindrome_1);
    RUN_TEST(test_Module_IsPalindrome_2);
    RUN_TEST(test_Module_IsPalindrome_3);
    RUN_TEST(test_Module_IsPalindrome_4);

    return UNITY_END();
}
