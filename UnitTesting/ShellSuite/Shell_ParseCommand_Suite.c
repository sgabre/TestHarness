#include <string.h>
#include <unity.h>

#include <Shell.h>
#include <Shell_io.h>




// Mock function for ioShell()->printf (since we can't actually print in a unit test)
void mock_printf(const char *format, ...) 
{
}

// Test setup and teardown (if needed)
void setUp(void)
{
    //ioShell()->getchar = getchar;
    //ioShell()->putchar = putchar;
    ioShell()->printf =mock_printf;
}

void tearDown(void) 
{


}

// Test cases
void test_Shell_ParseCommand_NullInput(void) 
{
    char *argv[5];
    TEST_ASSERT_EQUAL(0, mShell_ParseCommand(NULL, argv, 5));
}

void test_Shell_ParseCommand_NullArgv(void) 
{
    char input[] = "command arg1 arg2";
    TEST_ASSERT_EQUAL(0, mShell_ParseCommand(input, NULL, 5));
}

void test_Shell_ParseCommand_ValidCommand(void) 
{
    char input[] = "command arg1 arg2";
    char* argv[5] = {0};
    
    int argc = mShell_ParseCommand(input, argv, 5);
    
    TEST_ASSERT_EQUAL(3, argc);
    TEST_ASSERT_EQUAL_STRING("command", argv[0]);
    TEST_ASSERT_EQUAL_STRING("arg1", argv[1]);
    TEST_ASSERT_EQUAL_STRING("arg2", argv[2]);
    TEST_ASSERT_NULL(argv[3]);
}

void test_Shell_ParseCommand_MultipleSpaces(void) 
{
    char input[] = "   command   arg1   arg2   ";
    char *argv[5] = {0};
    
    int argc = mShell_ParseCommand(input, argv, 5);
    
    TEST_ASSERT_EQUAL(3, argc);
    TEST_ASSERT_EQUAL_STRING("command", argv[0]);
    TEST_ASSERT_EQUAL_STRING("arg1", argv[1]);
    TEST_ASSERT_EQUAL_STRING("arg2", argv[2]);
    TEST_ASSERT_NULL(argv[3]);
}

void test_Shell_ParseCommand_ExceedingMaxArgs(void) 
{
    char input[] = "cmd1 cmd2 cmd3 cmd4 cmd5 cmd6"; // 6 arguments
    char *argv[5] = {0};  // Max arguments = 4
    
    int argc = mShell_ParseCommand(input, argv, 4);
    
    TEST_ASSERT_EQUAL(4, argc);
    TEST_ASSERT_EQUAL_STRING("cmd1", argv[0]);
    TEST_ASSERT_EQUAL_STRING("cmd2", argv[1]);
    TEST_ASSERT_EQUAL_STRING("cmd3", argv[2]);
    TEST_ASSERT_EQUAL_STRING("cmd4", argv[3]);
    TEST_ASSERT_NULL(argv[4]);
}

void test_Shell_ParseCommand_EmptyString(void) 
{
    char input[] = "";
    char *argv[5] = {0};
    
    int argc = mShell_ParseCommand(input, argv, 5);
    
    TEST_ASSERT_EQUAL(0, argc);
    TEST_ASSERT_NULL(argv[0]);
}

void test_Shell_ParseCommand_OnlySpaces(void) 
{
    char input[] = "     ";
    char *argv[5] = {0};
    
    int argc = mShell_ParseCommand(input, argv, 5);
    
    TEST_ASSERT_EQUAL(0, argc);
    TEST_ASSERT_NULL(argv[0]);
}

// Test runner
int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(test_Shell_ParseCommand_NullInput);
    RUN_TEST(test_Shell_ParseCommand_NullArgv);
    RUN_TEST(test_Shell_ParseCommand_ValidCommand);
    RUN_TEST(test_Shell_ParseCommand_MultipleSpaces);
    RUN_TEST(test_Shell_ParseCommand_ExceedingMaxArgs);
    RUN_TEST(test_Shell_ParseCommand_EmptyString);
    RUN_TEST(test_Shell_ParseCommand_OnlySpaces);
    return UNITY_END();
}
