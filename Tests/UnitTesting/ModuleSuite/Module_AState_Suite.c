#include <stdlib.h>


#include "unity.h"
#include "Module.h"

// Use void pointer for test context
static void* testContext;  // Generic pointer to module context

void setUp(void) 
{
    // Initialize a test module context
    testContext = malloc( MODULE_CONTEXT_SIZE );

    if (testContext == NULL) 
    {
        TEST_FAIL_MESSAGE("Failed to allocate memory for test context.");
    }
    Module_Init(testContext); // Set initial event (optional)
}

void tearDown(void) 
{
    // Clean up after each test
    if (testContext != NULL) 
    {
        free(testContext);
        testContext = NULL;
    }
}

void test_mModule_AState_1(void) 
{
    uint8_t event = MODULE_1_EVENT;
    uint8_t expected_state = 0; // Set expected state after processing the event
    
    mModule_AStateWrapper(event);  // Call the wrapper function for mModule_AState

    // Assert that the state is as expected
    TEST_ASSERT_EQUAL(expected_state, mModule_GetStateWrapper() );
}

int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(test_mModule_AState_1);
    return UNITY_END();
}