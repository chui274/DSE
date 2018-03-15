/*******************************************************************************
* File Name: toma.h  
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

#if !defined(CY_PINS_toma_H) /* Pins toma_H */
#define CY_PINS_toma_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "toma_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 toma__PORT == 15 && ((toma__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    toma_Write(uint8 value);
void    toma_SetDriveMode(uint8 mode);
uint8   toma_ReadDataReg(void);
uint8   toma_Read(void);
void    toma_SetInterruptMode(uint16 position, uint16 mode);
uint8   toma_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the toma_SetDriveMode() function.
     *  @{
     */
        #define toma_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define toma_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define toma_DM_RES_UP          PIN_DM_RES_UP
        #define toma_DM_RES_DWN         PIN_DM_RES_DWN
        #define toma_DM_OD_LO           PIN_DM_OD_LO
        #define toma_DM_OD_HI           PIN_DM_OD_HI
        #define toma_DM_STRONG          PIN_DM_STRONG
        #define toma_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define toma_MASK               toma__MASK
#define toma_SHIFT              toma__SHIFT
#define toma_WIDTH              1u

/* Interrupt constants */
#if defined(toma__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in toma_SetInterruptMode() function.
     *  @{
     */
        #define toma_INTR_NONE      (uint16)(0x0000u)
        #define toma_INTR_RISING    (uint16)(0x0001u)
        #define toma_INTR_FALLING   (uint16)(0x0002u)
        #define toma_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define toma_INTR_MASK      (0x01u) 
#endif /* (toma__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define toma_PS                     (* (reg8 *) toma__PS)
/* Data Register */
#define toma_DR                     (* (reg8 *) toma__DR)
/* Port Number */
#define toma_PRT_NUM                (* (reg8 *) toma__PRT) 
/* Connect to Analog Globals */                                                  
#define toma_AG                     (* (reg8 *) toma__AG)                       
/* Analog MUX bux enable */
#define toma_AMUX                   (* (reg8 *) toma__AMUX) 
/* Bidirectional Enable */                                                        
#define toma_BIE                    (* (reg8 *) toma__BIE)
/* Bit-mask for Aliased Register Access */
#define toma_BIT_MASK               (* (reg8 *) toma__BIT_MASK)
/* Bypass Enable */
#define toma_BYP                    (* (reg8 *) toma__BYP)
/* Port wide control signals */                                                   
#define toma_CTL                    (* (reg8 *) toma__CTL)
/* Drive Modes */
#define toma_DM0                    (* (reg8 *) toma__DM0) 
#define toma_DM1                    (* (reg8 *) toma__DM1)
#define toma_DM2                    (* (reg8 *) toma__DM2) 
/* Input Buffer Disable Override */
#define toma_INP_DIS                (* (reg8 *) toma__INP_DIS)
/* LCD Common or Segment Drive */
#define toma_LCD_COM_SEG            (* (reg8 *) toma__LCD_COM_SEG)
/* Enable Segment LCD */
#define toma_LCD_EN                 (* (reg8 *) toma__LCD_EN)
/* Slew Rate Control */
#define toma_SLW                    (* (reg8 *) toma__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define toma_PRTDSI__CAPS_SEL       (* (reg8 *) toma__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define toma_PRTDSI__DBL_SYNC_IN    (* (reg8 *) toma__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define toma_PRTDSI__OE_SEL0        (* (reg8 *) toma__PRTDSI__OE_SEL0) 
#define toma_PRTDSI__OE_SEL1        (* (reg8 *) toma__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define toma_PRTDSI__OUT_SEL0       (* (reg8 *) toma__PRTDSI__OUT_SEL0) 
#define toma_PRTDSI__OUT_SEL1       (* (reg8 *) toma__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define toma_PRTDSI__SYNC_OUT       (* (reg8 *) toma__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(toma__SIO_CFG)
    #define toma_SIO_HYST_EN        (* (reg8 *) toma__SIO_HYST_EN)
    #define toma_SIO_REG_HIFREQ     (* (reg8 *) toma__SIO_REG_HIFREQ)
    #define toma_SIO_CFG            (* (reg8 *) toma__SIO_CFG)
    #define toma_SIO_DIFF           (* (reg8 *) toma__SIO_DIFF)
#endif /* (toma__SIO_CFG) */

/* Interrupt Registers */
#if defined(toma__INTSTAT)
    #define toma_INTSTAT            (* (reg8 *) toma__INTSTAT)
    #define toma_SNAP               (* (reg8 *) toma__SNAP)
    
	#define toma_0_INTTYPE_REG 		(* (reg8 *) toma__0__INTTYPE)
#endif /* (toma__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_toma_H */


/* [] END OF FILE */
