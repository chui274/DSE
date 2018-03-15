/*******************************************************************************
* File Name: Pulse.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pulse_H) /* Pins Pulse_H */
#define CY_PINS_Pulse_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pulse_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pulse__PORT == 15 && ((Pulse__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pulse_Write(uint8 value);
void    Pulse_SetDriveMode(uint8 mode);
uint8   Pulse_ReadDataReg(void);
uint8   Pulse_Read(void);
void    Pulse_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pulse_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pulse_SetDriveMode() function.
     *  @{
     */
        #define Pulse_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pulse_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pulse_DM_RES_UP          PIN_DM_RES_UP
        #define Pulse_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pulse_DM_OD_LO           PIN_DM_OD_LO
        #define Pulse_DM_OD_HI           PIN_DM_OD_HI
        #define Pulse_DM_STRONG          PIN_DM_STRONG
        #define Pulse_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pulse_MASK               Pulse__MASK
#define Pulse_SHIFT              Pulse__SHIFT
#define Pulse_WIDTH              1u

/* Interrupt constants */
#if defined(Pulse__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pulse_SetInterruptMode() function.
     *  @{
     */
        #define Pulse_INTR_NONE      (uint16)(0x0000u)
        #define Pulse_INTR_RISING    (uint16)(0x0001u)
        #define Pulse_INTR_FALLING   (uint16)(0x0002u)
        #define Pulse_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pulse_INTR_MASK      (0x01u) 
#endif /* (Pulse__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pulse_PS                     (* (reg8 *) Pulse__PS)
/* Data Register */
#define Pulse_DR                     (* (reg8 *) Pulse__DR)
/* Port Number */
#define Pulse_PRT_NUM                (* (reg8 *) Pulse__PRT) 
/* Connect to Analog Globals */                                                  
#define Pulse_AG                     (* (reg8 *) Pulse__AG)                       
/* Analog MUX bux enable */
#define Pulse_AMUX                   (* (reg8 *) Pulse__AMUX) 
/* Bidirectional Enable */                                                        
#define Pulse_BIE                    (* (reg8 *) Pulse__BIE)
/* Bit-mask for Aliased Register Access */
#define Pulse_BIT_MASK               (* (reg8 *) Pulse__BIT_MASK)
/* Bypass Enable */
#define Pulse_BYP                    (* (reg8 *) Pulse__BYP)
/* Port wide control signals */                                                   
#define Pulse_CTL                    (* (reg8 *) Pulse__CTL)
/* Drive Modes */
#define Pulse_DM0                    (* (reg8 *) Pulse__DM0) 
#define Pulse_DM1                    (* (reg8 *) Pulse__DM1)
#define Pulse_DM2                    (* (reg8 *) Pulse__DM2) 
/* Input Buffer Disable Override */
#define Pulse_INP_DIS                (* (reg8 *) Pulse__INP_DIS)
/* LCD Common or Segment Drive */
#define Pulse_LCD_COM_SEG            (* (reg8 *) Pulse__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pulse_LCD_EN                 (* (reg8 *) Pulse__LCD_EN)
/* Slew Rate Control */
#define Pulse_SLW                    (* (reg8 *) Pulse__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pulse_PRTDSI__CAPS_SEL       (* (reg8 *) Pulse__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pulse_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pulse__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pulse_PRTDSI__OE_SEL0        (* (reg8 *) Pulse__PRTDSI__OE_SEL0) 
#define Pulse_PRTDSI__OE_SEL1        (* (reg8 *) Pulse__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pulse_PRTDSI__OUT_SEL0       (* (reg8 *) Pulse__PRTDSI__OUT_SEL0) 
#define Pulse_PRTDSI__OUT_SEL1       (* (reg8 *) Pulse__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pulse_PRTDSI__SYNC_OUT       (* (reg8 *) Pulse__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pulse__SIO_CFG)
    #define Pulse_SIO_HYST_EN        (* (reg8 *) Pulse__SIO_HYST_EN)
    #define Pulse_SIO_REG_HIFREQ     (* (reg8 *) Pulse__SIO_REG_HIFREQ)
    #define Pulse_SIO_CFG            (* (reg8 *) Pulse__SIO_CFG)
    #define Pulse_SIO_DIFF           (* (reg8 *) Pulse__SIO_DIFF)
#endif /* (Pulse__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pulse__INTSTAT)
    #define Pulse_INTSTAT            (* (reg8 *) Pulse__INTSTAT)
    #define Pulse_SNAP               (* (reg8 *) Pulse__SNAP)
    
	#define Pulse_0_INTTYPE_REG 		(* (reg8 *) Pulse__0__INTTYPE)
#endif /* (Pulse__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pulse_H */


/* [] END OF FILE */
