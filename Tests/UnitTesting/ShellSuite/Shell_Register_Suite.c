#include <string.h>

#include <unity.h>

#include <Registry.h>


//extern ShellCommand_ts mCommands;

// Mock handler
void MockHandler(int argc, char *argv[]) {}

void setUp(void) 
{
    Shell_Delete();
}

void tearDown(void) {}


void test_Shell_Register_0(void)
{
    //Protocol_Register(uint32_t aCode, ProtocolHandler aHandler)
    Shell_Register(NULL, "Test command", MockHandler);
    // Check if command was not added
    TEST_ASSERT_EQUAL(0, Shell_Size());
}

void test_Shell_Register_1(void)
{
    //Protocol_Register(uint32_t aCode, ProtocolHandler aHandler)
    Shell_Register("test", NULL, MockHandler);
    // Check if command was not added
    TEST_ASSERT_EQUAL(0, Shell_Size());
}

// Test NULL handler
void test_Shell_Register_2(void) 
{
    Shell_Register("test", "Test command", NULL);
    // Check if command was not added
    TEST_ASSERT_EQUAL(0, Shell_Size());
}

// Test adding a command
void test_Shell_Register_3(void) 
{
    Shell_Register("test", "Test command", MockHandler);
    TEST_ASSERT_EQUAL(1, Shell_Size());
}

// Test duplicate command
void test_Shell_Register_4(void) 
{
    Shell_Register("test", "Test command", MockHandler);
    Shell_Register("test", "Test command", MockHandler);
    TEST_ASSERT_EQUAL(1, Shell_Size());
}

// Test exceeding max commands (STATIC_MEMORY mode)
void test_Shell_Register_5(void) 
{
    char name[32][10];
    
    for (size_t i = 0; i < 32; i++) 
    {
        sprintf(name[i], "cmd%zu", i);
        Shell_Register(name[i], "A command", MockHandler);
    }
    
    // Attempt to add one more
    Shell_Register("overflow", "Should fail", MockHandler);
    TEST_ASSERT_EQUAL(32, Shell_Size());
}

int main(void) 
{
    UNITY_BEGIN();
    
    RUN_TEST(test_Shell_Register_0);
    RUN_TEST(test_Shell_Register_1);
    RUN_TEST(test_Shell_Register_2);
    RUN_TEST(test_Shell_Register_3);
    RUN_TEST(test_Shell_Register_4);
    RUN_TEST(test_Shell_Register_5);
    
    return UNITY_END();
}
