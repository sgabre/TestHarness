#include <unity.h>

#include <Shell.h>
#include <Shell_io.h>

// Function prototype
int Shell_Gets(char* s, int len);

// Mock implementation of ioShell()
typedef struct 
{
    const char* input;  // Simulated input sequence
    int         index;    // Current input index
} MockIoShell;

MockIoShell mock_io;

void cmock_stream_ExpectAndReturn(const char* ptr)
{
    
}
//int (*getchar)(void);
//int (*putchar)(int character );

// Mock getchar() function
int mock_getchar(void) 
{
    if (mock_io.input[mock_io.index] == '\0') {
        return '\n';  // Simulate pressing "Enter" at end of input
    }
    return mock_io.input[mock_io.index++];
}

// Mock putchar() function (we don't need to verify printed characters in this test)
int mock_putchar(int c) 
{
    (void)c;  // Ignore output
    return 0;
}



// Setup and teardown (if needed)
void setUp(void) 
{ 
    mock_io.index = 0; 
    
    ioShell()->getchar = mock_getchar;
    ioShell()->putchar = mock_putchar;
    //ioShell()->printf =mock_printf;
}

void tearDown(void) 
{
    
}


// ---------- Test Cases ----------

void test_Shell_Gets_EmptyInput(void) 
{
    mock_io.input = "";  // Simulate pressing Enter immediately
    char buffer[10];
    
    int len = mShell_Gets(buffer, sizeof(buffer));
    
    TEST_ASSERT_EQUAL(0, len);
    TEST_ASSERT_EQUAL_STRING("", buffer);
}

void test_Shell_Gets_NormalInput(void) 
{
    mock_io.input = "hello\n";  
    char buffer[10];
    
    int len = mShell_Gets(buffer, sizeof(buffer));
    
    TEST_ASSERT_EQUAL(5, len);
    TEST_ASSERT_EQUAL_STRING("hello", buffer);
}

void test_Shell_Gets_InputWithBackspace(void) 
{
    mock_io.input = "abc\b\bxy\n";  // User types "abc", deletes "bc", then types "xy"
    char buffer[10];
    
    int len = mShell_Gets(buffer, sizeof(buffer));
    
    TEST_ASSERT_EQUAL(3, len);
    TEST_ASSERT_EQUAL_STRING("axy", buffer);
}

void test_Shell_Gets_BufferLimit(void) 
{
    mock_io.input = "1234567890abcdef\n";  // Input longer than buffer
    char buffer[10];
    
    int len = mShell_Gets(buffer, sizeof(buffer));  // Max size is 10
    
    TEST_ASSERT_EQUAL(9, len);  // 9 characters + 1 null terminator
    TEST_ASSERT_EQUAL_STRING("123456789", buffer);
}

void test_Shell_Gets_ExcessiveBackspace(void) 
{
    mock_io.input = "\b\bhello\n";  // Backspace before entering anything
    char buffer[10];
    
    int len = mShell_Gets(buffer, sizeof(buffer));
    
    TEST_ASSERT_EQUAL(5, len);
    TEST_ASSERT_EQUAL_STRING("hello", buffer);
}

// ---------- Test Runner ----------
int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(test_Shell_Gets_EmptyInput);
    RUN_TEST(test_Shell_Gets_NormalInput);
    RUN_TEST(test_Shell_Gets_InputWithBackspace);
    RUN_TEST(test_Shell_Gets_BufferLimit);
    RUN_TEST(test_Shell_Gets_ExcessiveBackspace);
    return UNITY_END();
}