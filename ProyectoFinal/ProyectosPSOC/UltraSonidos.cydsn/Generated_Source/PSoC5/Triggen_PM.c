/*******************************************************************************
* File Name: Triggen_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Triggen.h"

/* Check for removal by optimization */
#if !defined(Triggen_Sync_ctrl_reg__REMOVED)

static Triggen_BACKUP_STRUCT  Triggen_backup = {0u};

    
/*******************************************************************************
* Function Name: Triggen_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Triggen_SaveConfig(void) 
{
    Triggen_backup.controlState = Triggen_Control;
}


/*******************************************************************************
* Function Name: Triggen_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Triggen_RestoreConfig(void) 
{
     Triggen_Control = Triggen_backup.controlState;
}


/*******************************************************************************
* Function Name: Triggen_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Triggen_Sleep(void) 
{
    Triggen_SaveConfig();
}


/*******************************************************************************
* Function Name: Triggen_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Triggen_Wakeup(void)  
{
    Triggen_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
