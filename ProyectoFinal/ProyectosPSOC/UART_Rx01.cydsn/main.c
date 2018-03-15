/*******************************************************************************
* File Name: main.c
*
* Version: 2.1
*
* Description:
*  This project demonstrates the UART reception mechanism. 
*  Data typed on the hyperterminal is sent through serial port and displayed
*  on the LCD.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>

#define LCD_NUM_COLUMNS (16u)


int main()
{   
    char8 ch;       /* Data received from the Serial port */
    uint8 count = 0u;
    uint8 pos = 0u;

    CyGlobalIntEnable; /* Enable all interrupts by the processor. */


    while(1)
    {
        /* Check the UART status */
        while(Rx_1_Read()==1){
        LCD_Char_1_PrintString("Hola Amigo!");
        while(1);
    }
    }
}


/* [] END OF FILE */
