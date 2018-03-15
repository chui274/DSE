/*******************************************************************************
* File Name: DistOutHCSRO4.h  
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

#if !defined(CY_PINS_DistOutHCSRO4_H) /* Pins DistOutHCSRO4_H */
#define CY_PINS_DistOutHCSRO4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DistOutHCSRO4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DistOutHCSRO4_Write(uint8 value) ;
void    DistOutHCSRO4_SetDriveMode(uint8 mode) ;
uint8   DistOutHCSRO4_ReadDataReg(void) ;
uint8   DistOutHCSRO4_Read(void) ;
void    DistOutHCSRO4_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   DistOutHCSRO4_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DistOutHCSRO4_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define DistOutHCSRO4_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define DistOutHCSRO4_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define DistOutHCSRO4_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define DistOutHCSRO4_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define DistOutHCSRO4_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define DistOutHCSRO4_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define DistOutHCSRO4_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define DistOutHCSRO4_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DistOutHCSRO4_MASK               DistOutHCSRO4__MASK
#define DistOutHCSRO4_SHIFT              DistOutHCSRO4__SHIFT
#define DistOutHCSRO4_WIDTH              1u

/* Interrupt constants */
#if defined(DistOutHCSRO4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DistOutHCSRO4_SetInterruptMode() function.
     *  @{
     */
        #define DistOutHCSRO4_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define DistOutHCSRO4_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define DistOutHCSRO4_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define DistOutHCSRO4_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define DistOutHCSRO4_INTR_MASK      (0x01u)
#endif /* (DistOutHCSRO4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DistOutHCSRO4_PS                     (* (reg8 *) DistOutHCSRO4__PS)
/* Data Register */
#define DistOutHCSRO4_DR                     (* (reg8 *) DistOutHCSRO4__DR)
/* Port Number */
#define DistOutHCSRO4_PRT_NUM                (* (reg8 *) DistOutHCSRO4__PRT) 
/* Connect to Analog Globals */                                                  
#define DistOutHCSRO4_AG                     (* (reg8 *) DistOutHCSRO4__AG)                       
/* Analog MUX bux enable */
#define DistOutHCSRO4_AMUX                   (* (reg8 *) DistOutHCSRO4__AMUX) 
/* Bidirectional Enable */                                                        
#define DistOutHCSRO4_BIE                    (* (reg8 *) DistOutHCSRO4__BIE)
/* Bit-mask for Aliased Register Access */
#define DistOutHCSRO4_BIT_MASK               (* (reg8 *) DistOutHCSRO4__BIT_MASK)
/* Bypass Enable */
#define DistOutHCSRO4_BYP                    (* (reg8 *) DistOutHCSRO4__BYP)
/* Port wide control signals */                                                   
#define DistOutHCSRO4_CTL                    (* (reg8 *) DistOutHCSRO4__CTL)
/* Drive Modes */
#define DistOutHCSRO4_DM0                    (* (reg8 *) DistOutHCSRO4__DM0) 
#define DistOutHCSRO4_DM1                    (* (reg8 *) DistOutHCSRO4__DM1)
#define DistOutHCSRO4_DM2                    (* (reg8 *) DistOutHCSRO4__DM2) 
/* Input Buffer Disable Override */
#define DistOutHCSRO4_INP_DIS                (* (reg8 *) DistOutHCSRO4__INP_DIS)
/* LCD Common or Segment Drive */
#define DistOutHCSRO4_LCD_COM_SEG            (* (reg8 *) DistOutHCSRO4__LCD_COM_SEG)
/* Enable Segment LCD */
#define DistOutHCSRO4_LCD_EN                 (* (reg8 *) DistOutHCSRO4__LCD_EN)
/* Slew Rate Control */
#define DistOutHCSRO4_SLW                    (* (reg8 *) DistOutHCSRO4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DistOutHCSRO4_PRTDSI__CAPS_SEL       (* (reg8 *) DistOutHCSRO4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DistOutHCSRO4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DistOutHCSRO4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DistOutHCSRO4_PRTDSI__OE_SEL0        (* (reg8 *) DistOutHCSRO4__PRTDSI__OE_SEL0) 
#define DistOutHCSRO4_PRTDSI__OE_SEL1        (* (reg8 *) DistOutHCSRO4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DistOutHCSRO4_PRTDSI__OUT_SEL0       (* (reg8 *) DistOutHCSRO4__PRTDSI__OUT_SEL0) 
#define DistOutHCSRO4_PRTDSI__OUT_SEL1       (* (reg8 *) DistOutHCSRO4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DistOutHCSRO4_PRTDSI__SYNC_OUT       (* (reg8 *) DistOutHCSRO4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DistOutHCSRO4__SIO_CFG)
    #define DistOutHCSRO4_SIO_HYST_EN        (* (reg8 *) DistOutHCSRO4__SIO_HYST_EN)
    #define DistOutHCSRO4_SIO_REG_HIFREQ     (* (reg8 *) DistOutHCSRO4__SIO_REG_HIFREQ)
    #define DistOutHCSRO4_SIO_CFG            (* (reg8 *) DistOutHCSRO4__SIO_CFG)
    #define DistOutHCSRO4_SIO_DIFF           (* (reg8 *) DistOutHCSRO4__SIO_DIFF)
#endif /* (DistOutHCSRO4__SIO_CFG) */

/* Interrupt Registers */
#if defined(DistOutHCSRO4__INTSTAT)
    #define DistOutHCSRO4_INTSTAT             (* (reg8 *) DistOutHCSRO4__INTSTAT)
    #define DistOutHCSRO4_SNAP                (* (reg8 *) DistOutHCSRO4__SNAP)
    
	#define DistOutHCSRO4_0_INTTYPE_REG 		(* (reg8 *) DistOutHCSRO4__0__INTTYPE)
#endif /* (DistOutHCSRO4__INTSTAT) */

#endif /* End Pins DistOutHCSRO4_H */


/* [] END OF FILE */
