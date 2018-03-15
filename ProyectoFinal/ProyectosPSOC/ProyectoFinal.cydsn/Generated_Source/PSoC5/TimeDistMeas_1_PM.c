/*******************************************************************************
* File Name: TimeDistMeas_1_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "TimeDistMeas_1.h"

static TimeDistMeas_1_backupStruct TimeDistMeas_1_backup;


/*******************************************************************************
* Function Name: TimeDistMeas_1_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimeDistMeas_1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TimeDistMeas_1_SaveConfig(void) 
{
    #if (!TimeDistMeas_1_UsingFixedFunction)
        TimeDistMeas_1_backup.TimerUdb = TimeDistMeas_1_ReadCounter();
        TimeDistMeas_1_backup.InterruptMaskValue = TimeDistMeas_1_STATUS_MASK;
        #if (TimeDistMeas_1_UsingHWCaptureCounter)
            TimeDistMeas_1_backup.TimerCaptureCounter = TimeDistMeas_1_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!TimeDistMeas_1_UDB_CONTROL_REG_REMOVED)
            TimeDistMeas_1_backup.TimerControlRegister = TimeDistMeas_1_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: TimeDistMeas_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimeDistMeas_1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TimeDistMeas_1_RestoreConfig(void) 
{   
    #if (!TimeDistMeas_1_UsingFixedFunction)

        TimeDistMeas_1_WriteCounter(TimeDistMeas_1_backup.TimerUdb);
        TimeDistMeas_1_STATUS_MASK =TimeDistMeas_1_backup.InterruptMaskValue;
        #if (TimeDistMeas_1_UsingHWCaptureCounter)
            TimeDistMeas_1_SetCaptureCount(TimeDistMeas_1_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!TimeDistMeas_1_UDB_CONTROL_REG_REMOVED)
            TimeDistMeas_1_WriteControlRegister(TimeDistMeas_1_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: TimeDistMeas_1_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimeDistMeas_1_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void TimeDistMeas_1_Sleep(void) 
{
    #if(!TimeDistMeas_1_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(TimeDistMeas_1_CTRL_ENABLE == (TimeDistMeas_1_CONTROL & TimeDistMeas_1_CTRL_ENABLE))
        {
            /* Timer is enabled */
            TimeDistMeas_1_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            TimeDistMeas_1_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    TimeDistMeas_1_Stop();
    TimeDistMeas_1_SaveConfig();
}


/*******************************************************************************
* Function Name: TimeDistMeas_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimeDistMeas_1_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TimeDistMeas_1_Wakeup(void) 
{
    TimeDistMeas_1_RestoreConfig();
    #if(!TimeDistMeas_1_UDB_CONTROL_REG_REMOVED)
        if(TimeDistMeas_1_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                TimeDistMeas_1_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
