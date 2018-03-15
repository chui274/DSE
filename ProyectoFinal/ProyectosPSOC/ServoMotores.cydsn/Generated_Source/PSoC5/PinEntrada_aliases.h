/*******************************************************************************
* File Name: PinEntrada.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PinEntrada_ALIASES_H) /* Pins PinEntrada_ALIASES_H */
#define CY_PINS_PinEntrada_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define PinEntrada_0			(PinEntrada__0__PC)
#define PinEntrada_0_INTR	((uint16)((uint16)0x0001u << PinEntrada__0__SHIFT))

#define PinEntrada_INTR_ALL	 ((uint16)(PinEntrada_0_INTR))

#endif /* End Pins PinEntrada_ALIASES_H */


/* [] END OF FILE */
