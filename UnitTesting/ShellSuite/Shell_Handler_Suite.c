#include <unity.h>

#include <Shell.h>


// Mock implementation of ioShell()
typedef struct 
{
    const char* input;  // Simulated input sequence
    int         index;    // Current input index
} MockIoShell;

MockIoShell mock_io;

int Hit = 0;
void cmock_stream_ExpectAndReturn(const char* ptr)
{
    mock_io.index = 0; 
    mock_io.input = ptr;
    Hit = 0;
}

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

void MockHandler(int argc, char *argv[]) {printf("Execute");Hit = 1;}
void mock_printf(const char *format, ...) {}

void setUp(void)
{
    ioShell()->getchar = mock_getchar;
    ioShell()->putchar = mock_putchar;
    ioShell()->printf =mock_printf;
    Shell_Register("help", " ", MockHandler);
    Shell_Register(NULL, " ", MockHandler);
    Shell_Register("exit", " ", MockHandler);
    Shell_Register("version", " ", MockHandler);
}

void tearDown(void)
{
}

void test_Shell_Handler_1(void)
{
    cmock_stream_ExpectAndReturn("version");
    TEST_ASSERT_EQUAL(1, Hit);

}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_Shell_Handler_1);

    return UNITY_END();
}
