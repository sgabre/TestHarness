
/** @defgroup   Module  Module-Group
 *
 * detailed description of Module group
 * @{
 *
 *   @name       Module                                                           
 *   @file       Module.h                                                         
 * 
 *   @brief      Transmit and receive data over MDS COM port                                                             
 */

/*== Includes ================================================================*/
#include <ctype.h>

#include <string.h>

#include "Module.h"

/*== Defines =================================================================*/
#define MODULE_RAM_BASE_ADDR 1
#define MODULE_RAM_SIZE     10
#define MODULE_RAM_MAX_ADDR  (MODULE_RAM_BASE_ADDR + MODULE_RAM_SIZE)-1

#define MODULE_ROM_BASE_ADDR 40
#define MODULE_ROM_SIZE     10
#define MODULE_ROM_MAX_ADDR  (MODULE_RAM_BASE_ADDR + MODULE_RAM_SIZE)-1

/*== Enumerations ============================================================*/
typedef enum
{
    MODULE_A_STATE,
    MODULE_B_STATE,
    MODULE_C_STATE,
    MODULE_D_STATE,
    MODULE_E_STATE,
    MODULE_F_STATE,
    MODULE_G_STATE,
    MODULE_H_STATE,
    MODULE_NB_STATE
}eModuleState;

typedef enum
{
    MODULE_1_EVENT,
    MODULE_2_EVENT,
    MODULE_3_EVENT,
    MODULE_4_EVENT,
    MODULE_5_EVENT,
    MODULE_6_EVENT,
    MODULE_7_EVENT,
    MODULE_8_EVENT,
    MODULE_9_EVENT,
    MODULE_10_EVENT,
    MODULE_11_EVENT,
    MODULE_12_EVENT,
    MODULE_13_EVENT,
    MODULE_14_EVENT,
    MODULE_15_EVENT,
    MODULE_16_EVENT,
    MODULE_17_EVENT,
    MODULE_18_EVENT,
    MODULE_19_EVENT,
    MODULE_20_EVENT,
    MODULE_21_EVENT,
    MODULE_22_EVENT,
    MODULE_23_EVENT,
    MODULE_NB_EVENT
}eModuleEvent;

/*== Structures ==============================================================*/
struct ModuleContext_s 
{
    bool    IsInit;
    uint8_t State;  //< Single byte for a name or flag
    uint8_t Event;  //< Single byte for a name or flag
};


/*== Module Variables ========================================================*/

static ModuleContext_ts* mModuleContext;

/*== Private functions =======================================================*/
static eModuleError mModule_PrivateFunction(uint8_t aValue, size_t* aSize, uint8_t* aFrame);


/*============================================================================*/
/*== Private Module Functions ================================================*/
/*============================================================================*/

/** @brief      	Test loop transfer data over the MDS COM port
*
* @param[in] 		aAddr     The Value use in the function. 
*                              The Range Value is [MODULE_RAM_BASE_ADDR;MODULE_RAM_MAX_ADDR]
*                              The Range Value is [MODULE_ROM_BASE_ADDR;MODULE_ROM_MAX_ADDR]
* @param[in,out] 	aSize      [in] Nbr of bytes to write, [out] Nbr of written bytes
* @param[out] 		aFrame     Pointer to Frame
*
* @return     		MODULE_NO_ERROR, when no error occurs.
*                   MODULE_INVALID_PARAM_ERROR, when a invalid parameter is given.
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

void mModule_SetState(uint8_t aState)
{
    if(aState < MODULE_NB_STATE)
    {
        mModuleContext->State = aState;
    }
}

void mModule_AState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

void mModule_BState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

void mModule_CState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

void mModule_DState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

void mModule_EState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

void mModule_FState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

void mModule_GState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

void mModule_HState(uint8_t event)
{
    switch(event)
    {
        case MODULE_1_EVENT:
            
            break;
        
        default:
            
            break;
    }
}

//Base on: https://uu.diva-portal.org/smash/get/diva2:1776033/FULLTEXT01.pdf
void mModule_StateMachine(void)
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
/*== Public Module Functions ================================================*/
/*============================================================================*/

int8_t Module_Function(int8_t a, int8_t b, int8_t c)
{
    return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}



bool Module_IsPalindrome(const char *str) 
{
    if (str == NULL) 
        return false;  // Vérification de sécurité
    
    const char *debut = str;  
    const char *fin = str + strlen(str) - 1;
    
    while (debut < fin) 
        {
            // Ignorer les espaces et caractères non alphanumériques
            while (debut < fin && !isalnum((unsigned char)*debut)) 
                debut++;
            while (debut < fin && !isalnum((unsigned char)*fin)) 
                fin--;
            
            // Comparaison insensible à la casse
            if (tolower((unsigned char)*debut) != tolower((unsigned char)*fin)) 
                {
                    return false;  // Pas un palindrome
                }
            
            debut++;
            fin--;
        }
    
    return true;  // C'est un palindrome
}
