#include <unity.h>

#include <Shell.h>
#include <Shell_io.h>

void MockHandler(int argc, char *argv[]) {}
void mock_printf(const char *format, ...) {}

void setUp(void)
{
    ioShell()->printf =mock_printf;
    Shell_Register("help", " ", MockHandler);
    Shell_Register(NULL, " ", MockHandler);
    Shell_Register("exit", " ", MockHandler);
    Shell_Register("version", " ", MockHandler);
    
}

void tearDown(void)
{
    Shell_Delete();
}

// ---------- Test Cases ----------



void test_mShell_SearchCommand_NullInput(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand(NULL);
    TEST_ASSERT_NULL(cmd);
}

void test_mShell_SearchCommand_EmptyString(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand("");
    TEST_ASSERT_NULL(cmd);
}

void test_mShell_SearchCommand_ValidCommand(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand("help");
    TEST_ASSERT_NOT_NULL(cmd);
    TEST_ASSERT_EQUAL_STRING("help", cmd->Name);
}

void test_mShell_SearchCommand_InvalidCommand(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand("unknown");
    TEST_ASSERT_NULL(cmd);
}

void test_mShell_SearchCommand_LastCommand(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand("version");
    TEST_ASSERT_NOT_NULL(cmd);
    TEST_ASSERT_EQUAL_STRING("version", cmd->Name);
}

void test_mShell_SearchCommand_CaseSensitivity(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand("HELP");  // Assuming case-sensitive
    TEST_ASSERT_NULL(cmd);
}

void test_mShell_SearchCommand_NoCommandRegister(void) 
{
    Shell_Delete();
    const ShellCommand_ts *cmd = mShell_SearchCommand("help");
    TEST_ASSERT_NULL(cmd);
}

void test_mShell_SearchCommand_matching_prefix(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand("he");
    TEST_ASSERT_NULL(cmd);
}

void test_mShell_SearchCommand_different_case(void) 
{
    const ShellCommand_ts *cmd = mShell_SearchCommand("Help");
    TEST_ASSERT_NULL(cmd);
}

// ---------- Test Runner ----------
int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(test_mShell_SearchCommand_ValidCommand);
    RUN_TEST(test_mShell_SearchCommand_InvalidCommand);
    RUN_TEST(test_mShell_SearchCommand_NullInput);
    RUN_TEST(test_mShell_SearchCommand_LastCommand);
    RUN_TEST(test_mShell_SearchCommand_EmptyString);
    RUN_TEST(test_mShell_SearchCommand_CaseSensitivity);
    RUN_TEST(test_mShell_SearchCommand_NoCommandRegister);
    RUN_TEST(test_mShell_SearchCommand_matching_prefix);
    RUN_TEST(test_mShell_SearchCommand_different_case);
    return UNITY_END();
}
