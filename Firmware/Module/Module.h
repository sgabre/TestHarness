#ifndef _MODULE_H_
#define _MODULE_H_

/** @defgroup   MDS  MDS-Group
*
* detailed description of MDS group
* @{
*
*   @name       MDS                                                           
*   @file       MDS.h                                                         
* 
*   @brief      Transmit and receive data over MDS COM port                                                             
*/

/*== Includes ================================================================*/
#include <stdbool.h>
#include <stdint.h>

/*== Defines =================================================================*/

/*== Constants ============================================================== */

/*== types ================================================================== */
typedef struct ModuleContext_s ModuleContext_ts;

/*== Enumerations ============================================================*/
typedef enum
{
	MODULE_UNDEFINE_ERROR = -1,
	MODULE_NO_ERROR,
	MODULE_INVALID_PARAM_ERROR,
	MODULE_NB_ERROR
}eModuleError;

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
int8_t Module_Function(int8_t a, int8_t b, int8_t c);


/// @} // end of Group
/// @}

#endif /* _MODULE_H_ */
