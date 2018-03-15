/*******************************************************************************
* File Name: foto.h  
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

#if !defined(CY_PINS_foto_H) /* Pins foto_H */
#define CY_PINS_foto_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "foto_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 foto__PORT == 15 && ((foto__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    foto_Write(uint8 value);
void    foto_SetDriveMode(uint8 mode);
uint8   foto_ReadDataReg(void);
uint8   foto_Read(void);
void    foto_SetInterruptMode(uint16 position, uint16 mode);
uint8   foto_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the foto_SetDriveMode() function.
     *  @{
     */
        #define foto_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define foto_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define foto_DM_RES_UP          PIN_DM_RES_UP
        #define foto_DM_RES_DWN         PIN_DM_RES_DWN
        #define foto_DM_OD_LO           PIN_DM_OD_LO
        #define foto_DM_OD_HI           PIN_DM_OD_HI
        #define foto_DM_STRONG          PIN_DM_STRONG
        #define foto_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define foto_MASK               foto__MASK
#define foto_SHIFT              foto__SHIFT
#define foto_WIDTH              1u

/* Interrupt constants */
#if defined(foto__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in foto_SetInterruptMode() function.
     *  @{
     */
        #define foto_INTR_NONE      (uint16)(0x0000u)
        #define foto_INTR_RISING    (uint16)(0x0001u)
        #define foto_INTR_FALLING   (uint16)(0x0002u)
        #define foto_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define foto_INTR_MASK      (0x01u) 
#endif /* (foto__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define foto_PS                     (* (reg8 *) foto__PS)
/* Data Register */
#define foto_DR                     (* (reg8 *) foto__DR)
/* Port Number */
#define foto_PRT_NUM                (* (reg8 *) foto__PRT) 
/* Connect to Analog Globals */                                                  
#define foto_AG                     (* (reg8 *) foto__AG)                       
/* Analog MUX bux enable */
#define foto_AMUX                   (* (reg8 *) foto__AMUX) 
/* Bidirectional Enable */                                                        
#define foto_BIE                    (* (reg8 *) foto__BIE)
/* Bit-mask for Aliased Register Access */
#define foto_BIT_MASK               (* (reg8 *) foto__BIT_MASK)
/* Bypass Enable */
#define foto_BYP                    (* (reg8 *) foto__BYP)
/* Port wide control signals */                                                   
#define foto_CTL                    (* (reg8 *) foto__CTL)
/* Drive Modes */
#define foto_DM0                    (* (reg8 *) foto__DM0) 
#define foto_DM1                    (* (reg8 *) foto__DM1)
#define foto_DM2                    (* (reg8 *) foto__DM2) 
/* Input Buffer Disable Override */
#define foto_INP_DIS                (* (reg8 *) foto__INP_DIS)
/* LCD Common or Segment Drive */
#define foto_LCD_COM_SEG            (* (reg8 *) foto__LCD_COM_SEG)
/* Enable Segment LCD */
#define foto_LCD_EN                 (* (reg8 *) foto__LCD_EN)
/* Slew Rate Control */
#define foto_SLW                    (* (reg8 *) foto__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define foto_PRTDSI__CAPS_SEL       (* (reg8 *) foto__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define foto_PRTDSI__DBL_SYNC_IN    (* (reg8 *) foto__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define foto_PRTDSI__OE_SEL0        (* (reg8 *) foto__PRTDSI__OE_SEL0) 
#define foto_PRTDSI__OE_SEL1        (* (reg8 *) foto__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define foto_PRTDSI__OUT_SEL0       (* (reg8 *) foto__PRTDSI__OUT_SEL0) 
#define foto_PRTDSI__OUT_SEL1       (* (reg8 *) foto__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define foto_PRTDSI__SYNC_OUT       (* (reg8 *) foto__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(foto__SIO_CFG)
    #define foto_SIO_HYST_EN        (* (reg8 *) foto__SIO_HYST_EN)
    #define foto_SIO_REG_HIFREQ     (* (reg8 *) foto__SIO_REG_HIFREQ)
    #define foto_SIO_CFG            (* (reg8 *) foto__SIO_CFG)
    #define foto_SIO_DIFF           (* (reg8 *) foto__SIO_DIFF)
#endif /* (foto__SIO_CFG) */

/* Interrupt Registers */
#if defined(foto__INTSTAT)
    #define foto_INTSTAT            (* (reg8 *) foto__INTSTAT)
    #define foto_SNAP               (* (reg8 *) foto__SNAP)
    
	#define foto_0_INTTYPE_REG 		(* (reg8 *) foto__0__INTTYPE)
#endif /* (foto__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_foto_H */


/* [] END OF FILE */
