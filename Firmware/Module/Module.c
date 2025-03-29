
/**                                                          
 *   @file       Module.c                                                         
 * 
 *   @brief      Module Source File Brief Description                                                             
 */

/*== Includes ================================================================*/
#include <ctype.h>

#include <string.h>

#include "Module.h"

/*== Defines =================================================================*/

/** 
 * @brief      This macro calculates the maximum address for RAM. 
 * @details    This value is used for range checking when accessing the RAM.
 */
#define MODULE_RAM_BASE_ADDR    1                                               /**< Base address of RAM */
#define MODULE_RAM_SIZE         10                                              /**< Size of RAM */
#define MODULE_RAM_MAX_ADDR     (MODULE_RAM_BASE_ADDR + MODULE_RAM_SIZE - 1)    /**< Max address of RAM */


/** 
 * @brief      This macro calculates the maximum address for ROM. 
 * @details    This value is used for range checking when accessing the ROM.
 */
#define MODULE_ROM_BASE_ADDR    40                                               /**< Base address of ROM */
#define MODULE_ROM_SIZE         10                                               /**< Size of ROM */
#define MODULE_ROM_MAX_ADDR     (MODULE_ROM_BASE_ADDR + MODULE_ROM_SIZE - 1)     /**< Max address of ROM */

/*== Enumerations ============================================================*/

/**
 * @enum eModuleState
 * @brief Enumeration representing different module states.
 */
typedef enum
{
    MODULE_A_STATE, /**< State A */
    MODULE_B_STATE, /**< State B */
    MODULE_C_STATE, /**< State C */
    MODULE_D_STATE, /**< State D */
    MODULE_E_STATE, /**< State E */
    MODULE_F_STATE, /**< State F */
    MODULE_G_STATE, /**< State G */
    MODULE_H_STATE, /**< State H */
    MODULE_NB_STATE /**< Number of states */
} eModuleState;



/*== Structures ==============================================================*/

/**
 * @struct ModuleContext_s
 * @brief Structure representing module context.
 */
struct ModuleContext_s 
{
    bool    IsInit; /**< Indicates if the module is initialized */
    uint8_t State;  /**< Current module state */
    uint8_t Event;  /**< Current module event */
};


/*== Module Variables ========================================================*/

size_t MODULE_CONTEXT_SIZE = sizeof(ModuleContext_ts);

static ModuleContext_ts* mModuleContext; /**< Module context instance */

/*== Private functions =======================================================*/
static eModuleError mModule_PrivateFunction(uint8_t aValue, size_t* aSize, uint8_t* aFrame);


/*============================================================================*/
/*== Private Module Functions ================================================*/
/*============================================================================*/

/** 
 * @brief Tests data transfer over the MDS COM port.
 * 
 * @param[in]  aAddr  Address value.
 *                    - RAM Range: [MODULE_RAM_BASE_ADDR; MODULE_RAM_MAX_ADDR]
 *                    - ROM Range: [MODULE_ROM_BASE_ADDR; MODULE_ROM_MAX_ADDR]
 * @param[in,out] aSize  [in] Number of bytes to write, [out] Number of bytes written.
 * @param[out] aFrame Pointer to the frame buffer.
 * 
 * @return MODULE_NO_ERROR if successful.
 *         MODULE_INVALID_PARAM_ERROR if an invalid parameter is given.
 */
static eModuleError mModule_PrivateFunction(uint8_t aAddr, size_t* aSize, uint8_t* aFrame)
{
    eModuleError Error = MODULE_UNDEFINE_ERROR;
    
    if(aSize != NULL)
    {
        Error = MODULE_INVALID_PARAM_ERROR;
    }
    else if(aFrame != NULL)
    {
        Error = MODULE_INVALID_PARAM_ERROR;
    }
    else if( (aAddr < MODULE_RAM_BASE_ADDR) && (aAddr > MODULE_RAM_MAX_ADDR) )
    {
        Error = MODULE_INVALID_PARAM_ERROR;
    }
    else if( (aAddr < MODULE_ROM_BASE_ADDR) && (aAddr > MODULE_ROM_MAX_ADDR) )
    {
        Error = MODULE_INVALID_PARAM_ERROR;
    }
    else 
    {
        Error = MODULE_NO_ERROR;
    }
    
    return Error;
}

/**
 * @brief Updates the module state.
 * @param[in] aState The new state.
 */
static void mModule_SetState(uint8_t aState)
{
    if(aState < MODULE_NB_STATE)
    {
        mModuleContext->State = aState;
    }
}

/**
 * @brief Handles state transitions for the module in the A state.
 * 
 * This function processes the events specific to the A state of the module. Based on the received event,
 * the function will execute actions or transition to other states.
 * 
 * Currently, the function supports handling the `MODULE_1_EVENT`, but additional events can be added as
 * needed to handle other scenarios within the A state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function is designed to be called when the module is in the `MODULE_A_STATE`.
 */
static void mModule_AState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}

/**
 * @brief Handles state transitions for the module in the B state.
 * 
 * This function processes the events specific to the B state of the module. Depending on the received event,
 * it executes actions or transitions to other states.
 * 
 * Currently, the function supports handling the `MODULE_1_EVENT`, but additional events can be added as
 * required for other actions within the B state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function is called when the module is in the `MODULE_B_STATE`.
 */
static void mModule_BState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}

/**
 * @brief Handles state transitions for the module in the C state.
 * 
 * This function processes events specific to the C state of the module. It handles the event actions
 * and determines if a state transition is necessary.
 * 
 * Currently, the function supports handling the `MODULE_1_EVENT`, but more events can be added for
 * handling additional actions within the C state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function should be called when the module is in the `MODULE_C_STATE`.
 */
static void mModule_CState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}

/**
 * @brief Handles state transitions for the module in the D state.
 * 
 * This function processes events specific to the D state of the module. It checks for the occurrence
 * of events and executes the necessary actions based on the current state.
 * 
 * Currently, the function supports handling the `MODULE_1_EVENT`, but additional events can be added
 * to handle other behaviors within the D state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function is invoked when the module is in the `MODULE_D_STATE`.
 */
static void mModule_DState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}


/**
 * @brief Handles state transitions for the module in the E state.
 * 
 * This function processes events that are specific to the E state of the module. Depending on the event received,
 * the function will execute corresponding actions or transition to other states.
 * 
 * Currently, the function handles the `MODULE_1_EVENT`, but it can be extended to manage additional events 
 * for other actions within the E state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function is intended to be called when the module is in the `MODULE_E_STATE`.
 */
static void mModule_EState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}


/**
 * @brief Handles state transitions for the module in the F state.
 * 
 * This function processes events specific to the F state of the module. It checks for the occurrence
 * of events and takes the necessary actions or transitions to other states.
 * 
 * Currently, the function supports handling the `MODULE_1_EVENT`, but additional events can be added
 * to manage further behaviors within the F state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function is invoked when the module is in the `MODULE_F_STATE`.
 */
static void mModule_FState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}


/**
 * @brief Handles state transitions for the module in the G state.
 * 
 * This function processes events specific to the G state of the module. It determines the necessary actions 
 * based on the received events, facilitating transitions to other states as required.
 * 
 * Currently, it handles the `MODULE_1_EVENT`, but additional events can be added to manage other behaviors 
 * within the G state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function is invoked when the module is in the `MODULE_G_STATE`.
 */
static void mModule_GState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}


/**
 * @brief Handles state transitions for the module in the H state.
 * 
 * This function processes events that are specific to the H state of the module. It executes actions 
 * based on the received events and facilitates transitions to other states as necessary.
 * 
 * Currently, the function handles the `MODULE_1_EVENT`, but more events can be added to manage other
 * behaviors within the H state.
 * 
 * @param[in] event The event that triggers the state transition. 
 *                  The valid events are defined in the `eModuleEvent` enum.
 * 
 * @note This function is intended to be called when the module is in the `MODULE_H_STATE`.
 */
static void mModule_HState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            // Handle the MODULE_1_EVENT here.
            break;
        
        default:
            // Handle unknown or unimplemented events.
            break;
    }
}


/**
 * @brief State machine handling function.
 * 
 * This function implements the state machine logic for the module. It processes events 
 * and transitions between different states based on the current state and event.
 * 
 * The state machine follows a set of predefined states and events to control the module's behavior.
 * Each state corresponds to a specific behavior, and the event triggers the transition to another state.
 * 
 * @note This function is designed to be called periodically to ensure state transitions occur as needed.
 * 
 * @see mModule_AState
 * @see mModule_BState
 * @see mModule_CState
 * @see mModule_DState
 * @see mModule_EState
 * @see mModule_FState
 * @see mModule_GState
 * @see mModule_HState
 * 
 * @reference "State Machine Model for Embedded Systems: A Case Study" (https://uu.diva-portal.org/smash/get/diva2:1776033/FULLTEXT01.pdf)
 */
static void mModule_StateMachine(void)
{
    uint8_t event = 0;
    
    //Event_WaitFlag(event);
    
    switch(mModuleContext->State)
    {
        case MODULE_A_STATE:
            mModule_AState(event);
            break;
        
        case MODULE_B_STATE:
            mModule_BState(event);
            break;
        
        case MODULE_C_STATE:
            mModule_CState(event);
            break;
        
        case MODULE_D_STATE:
            mModule_DState(event);
            break;
        
        case MODULE_E_STATE:
            mModule_EState(event);
            break;
        
        case MODULE_F_STATE:
            mModule_FState(event);
            break;
        
        case MODULE_G_STATE:
            mModule_GState(event);
            break;
        
        case MODULE_H_STATE:
            mModule_HState(event);
            break;
        
        default:
            
            break;
    }
}

/*============================================================================*/
/*== Public Module Functions =================================================*/
/*============================================================================*/

int8_t Module_PublicFunction(int8_t a, int8_t b, int8_t c)
{
    return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}

void Module_Init(void* aContext)
{
    // Ensure aContext is not NULL and then cast it to the correct type
    if (aContext != NULL) 
    {
        mModuleContext = (ModuleContext_ts*)aContext;
        
        // Check if the module has not been initialized, and if so, initialize it
        if (mModuleContext->IsInit != true) 
        {
            mModuleContext->IsInit = true;
        }
    }
}


/*============================================================================*/
/*== Wrap Functions ==========================================================*/
/*============================================================================*/


// Wrapper functions for testing
#ifdef UNIT_TEST_WRAPPER
uint8_t mModule_GetStateWrapper(void)
{
    return mModuleContext->State;
}

void mModule_AStateWrapper(uint8_t event)
{
    mModule_AState(event);
}

void mModule_BStateWrapper(uint8_t event)
{
    mModule_BState(event);
}

void mModule_CStateWrapper(uint8_t event)
{
    mModule_CState(event);
}

void mModule_DStateWrapper(uint8_t event)
{
    mModule_DState(event);
}

void mModule_EStateWrapper(uint8_t event)
{
    mModule_EState(event);
}

void mModule_FStateWrapper(uint8_t event)
{
    mModule_FState(event);
}

void mModule_GStateWrapper(uint8_t event)
{
    mModule_GState(event);
}

void mModule_HStateWrapper(uint8_t event)
{
    mModule_HState(event);
}
#endif