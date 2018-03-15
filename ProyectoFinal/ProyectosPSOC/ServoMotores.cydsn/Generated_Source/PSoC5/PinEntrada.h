/*******************************************************************************
* File Name: PinEntrada.h  
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

#if !defined(CY_PINS_PinEntrada_H) /* Pins PinEntrada_H */
#define CY_PINS_PinEntrada_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinEntrada_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinEntrada__PORT == 15 && ((PinEntrada__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinEntrada_Write(uint8 value);
void    PinEntrada_SetDriveMode(uint8 mode);
uint8   PinEntrada_ReadDataReg(void);
uint8   PinEntrada_Read(void);
void    PinEntrada_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinEntrada_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinEntrada_SetDriveMode() function.
     *  @{
     */
        #define PinEntrada_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinEntrada_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinEntrada_DM_RES_UP          PIN_DM_RES_UP
        #define PinEntrada_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinEntrada_DM_OD_LO           PIN_DM_OD_LO
        #define PinEntrada_DM_OD_HI           PIN_DM_OD_HI
        #define PinEntrada_DM_STRONG          PIN_DM_STRONG
        #define PinEntrada_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinEntrada_MASK               PinEntrada__MASK
#define PinEntrada_SHIFT              PinEntrada__SHIFT
#define PinEntrada_WIDTH              1u

/* Interrupt constants */
#if defined(PinEntrada__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinEntrada_SetInterruptMode() function.
     *  @{
     */
        #define PinEntrada_INTR_NONE      (uint16)(0x0000u)
        #define PinEntrada_INTR_RISING    (uint16)(0x0001u)
        #define PinEntrada_INTR_FALLING   (uint16)(0x0002u)
        #define PinEntrada_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinEntrada_INTR_MASK      (0x01u) 
#endif /* (PinEntrada__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinEntrada_PS                     (* (reg8 *) PinEntrada__PS)
/* Data Register */
#define PinEntrada_DR                     (* (reg8 *) PinEntrada__DR)
/* Port Number */
#define PinEntrada_PRT_NUM                (* (reg8 *) PinEntrada__PRT) 
/* Connect to Analog Globals */                                                  
#define PinEntrada_AG                     (* (reg8 *) PinEntrada__AG)                       
/* Analog MUX bux enable */
#define PinEntrada_AMUX                   (* (reg8 *) PinEntrada__AMUX) 
/* Bidirectional Enable */                                                        
#define PinEntrada_BIE                    (* (reg8 *) PinEntrada__BIE)
/* Bit-mask for Aliased Register Access */
#define PinEntrada_BIT_MASK               (* (reg8 *) PinEntrada__BIT_MASK)
/* Bypass Enable */
#define PinEntrada_BYP                    (* (reg8 *) PinEntrada__BYP)
/* Port wide control signals */                                                   
#define PinEntrada_CTL                    (* (reg8 *) PinEntrada__CTL)
/* Drive Modes */
#define PinEntrada_DM0                    (* (reg8 *) PinEntrada__DM0) 
#define PinEntrada_DM1                    (* (reg8 *) PinEntrada__DM1)
#define PinEntrada_DM2                    (* (reg8 *) PinEntrada__DM2) 
/* Input Buffer Disable Override */
#define PinEntrada_INP_DIS                (* (reg8 *) PinEntrada__INP_DIS)
/* LCD Common or Segment Drive */
#define PinEntrada_LCD_COM_SEG            (* (reg8 *) PinEntrada__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinEntrada_LCD_EN                 (* (reg8 *) PinEntrada__LCD_EN)
/* Slew Rate Control */
#define PinEntrada_SLW                    (* (reg8 *) PinEntrada__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinEntrada_PRTDSI__CAPS_SEL       (* (reg8 *) PinEntrada__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinEntrada_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinEntrada__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinEntrada_PRTDSI__OE_SEL0        (* (reg8 *) PinEntrada__PRTDSI__OE_SEL0) 
#define PinEntrada_PRTDSI__OE_SEL1        (* (reg8 *) PinEntrada__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinEntrada_PRTDSI__OUT_SEL0       (* (reg8 *) PinEntrada__PRTDSI__OUT_SEL0) 
#define PinEntrada_PRTDSI__OUT_SEL1       (* (reg8 *) PinEntrada__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinEntrada_PRTDSI__SYNC_OUT       (* (reg8 *) PinEntrada__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinEntrada__SIO_CFG)
    #define PinEntrada_SIO_HYST_EN        (* (reg8 *) PinEntrada__SIO_HYST_EN)
    #define PinEntrada_SIO_REG_HIFREQ     (* (reg8 *) PinEntrada__SIO_REG_HIFREQ)
    #define PinEntrada_SIO_CFG            (* (reg8 *) PinEntrada__SIO_CFG)
    #define PinEntrada_SIO_DIFF           (* (reg8 *) PinEntrada__SIO_DIFF)
#endif /* (PinEntrada__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinEntrada__INTSTAT)
    #define PinEntrada_INTSTAT            (* (reg8 *) PinEntrada__INTSTAT)
    #define PinEntrada_SNAP               (* (reg8 *) PinEntrada__SNAP)
    
	#define PinEntrada_0_INTTYPE_REG 		(* (reg8 *) PinEntrada__0__INTTYPE)
#endif /* (PinEntrada__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinEntrada_H */


/* [] END OF FILE */
