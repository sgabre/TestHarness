#ifndef _MODULE_H_
#define _MODULE_H_

/** 
 * @defgroup   Module  Module-Group
 * @brief      Detailed description of the Module group
 * @{
 * 
 * @name       Module
 * @file       Module.h
 * 
 * @brief      Module Header File Brief Description
 *             This file provides declarations for the module's public interface.
 */

/*== Includes ================================================================*/
#include <stdbool.h>
#include <stdint.h>

/*== Defines =================================================================*/

/*== Constants ============================================================== */
extern size_t MODULE_CONTEXT_SIZE;
/*== types ================================================================== */

/**
 * @typedef ModuleContext_ts
 * @brief Typedef for the module context structure.
 * 
 * This typedef defines the alias for the structure `ModuleContext_s`, which holds the context of the module. 
 * It is used to store information about the module's state, event, and initialization status.
 * 
 * @see ModuleContext_s
 */
typedef struct ModuleContext_s ModuleContext_ts;

/*== Enumerations ============================================================*/

/**
 * @enum eModuleError
 * @brief Enumeration representing possible error codes in the module.
 * 
 * This enum defines the error codes returned by the module's functions. 
 * It is used to indicate the result of an operation and to help with debugging.
 */
typedef enum
{
    MODULE_UNDEFINE_ERROR = -1, /**< Undefined error, used when no specific error is defined */
    MODULE_NO_ERROR,            /**< No error, operation was successful */
    MODULE_INVALID_PARAM_ERROR, /**< Invalid parameter error, returned when invalid input is provided */
    MODULE_NB_ERROR             /**< Number of error codes, used for array bounds or iteration */
} eModuleError;


/**
 * @enum eModuleEvent
 * @brief Enumeration representing different module events.
 */
typedef enum
{
    MODULE_1_EVENT,  /**< Event 1 */
    MODULE_2_EVENT,  /**< Event 2 */
    MODULE_3_EVENT,  /**< Event 3 */
    MODULE_4_EVENT,  /**< Event 4 */
    MODULE_5_EVENT,  /**< Event 5 */
    MODULE_6_EVENT,  /**< Event 6 */
    MODULE_7_EVENT,  /**< Event 7 */
    MODULE_8_EVENT,  /**< Event 8 */
    MODULE_9_EVENT,  /**< Event 9 */
    MODULE_10_EVENT, /**< Event 10 */
    MODULE_11_EVENT, /**< Event 11 */
    MODULE_12_EVENT, /**< Event 12 */
    MODULE_13_EVENT, /**< Event 13 */
    MODULE_14_EVENT, /**< Event 14 */
    MODULE_15_EVENT, /**< Event 15 */
    MODULE_16_EVENT, /**< Event 16 */
    MODULE_17_EVENT, /**< Event 17 */
    MODULE_18_EVENT, /**< Event 18 */
    MODULE_19_EVENT, /**< Event 19 */
    MODULE_20_EVENT, /**< Event 20 */
    MODULE_21_EVENT, /**< Event 21 */
    MODULE_22_EVENT, /**< Event 22 */
    MODULE_23_EVENT, /**< Event 23 */
    MODULE_NB_EVENT  /**< Number of events */
} eModuleEvent;

/*== structures ============================================================= */


/*== Public functions ======================================================= */

/** @brief      	Test loop transfer data over the MDS COM port
 *
 * @param[in] 		Command   TBD
 * @param[in,out] 	Size      [in] Nbr of bytes to write, [out] Nbr of written bytes
 * @param[out] 		Frame     Pointer to Frame
 *
 * @return     		MODULE_NO_ERROR, when no error occurs.
 */
int8_t Module_PublicFunction(int8_t a, int8_t b, int8_t c);


/**
 * @brief Initializes the module if not already initialized.
 * 
 * This function checks if the module has been previously initialized by evaluating the `IsInit` flag in the
 * module context. If the module is not yet initialized, it sets the `IsInit` flag to `true`, marking the 
 * module as initialized.
 * 
 * @note This function ensures that initialization only happens once. It should be called before any module 
 *       operations are executed.
 */
void Module_Init(void* aContext);

/// @} // end of Group
/// @}

#ifdef UNIT_TEST_WRAPPER

// Declare wrapper functions for testing
uint8_t mModule_GetStateWrapper(void);
void mModule_AStateWrapper(uint8_t event);
void mModule_BStateWrapper(uint8_t event);
void mModule_CStateWrapper(uint8_t event);
void mModule_DStateWrapper(uint8_t event);
void mModule_EStateWrapper(uint8_t event);
void mModule_FStateWrapper(uint8_t event);
void mModule_GStateWrapper(uint8_t event);
void mModule_HStateWrapper(uint8_t event);

#endif // UNIT_TESTING

#endif /* _MODULE_H_ */
