/*******************************************************************************
* File Name: main.c
*
* Version: 3.20
*
* Description:
*  This is source code for the datasheet example of the EZI2C and I2C
*  components.
*
*  The project explains the usage of EZI2C slave and I2C master components. In
*  the project when switch SW1 is pressed the I2C master writes a corresponding
*  message to the EZI2C slave and when switch SW2 is pressed the I2C master will
*  read back the data from the slave. Both the written and read back data are
*  displayed on LCD if both write and read operations happens successfully.
*
*  Display legend:
*   First string:
*    WR: xx xx xx xx 
*       WR:- Data being written by I2C Mater to EZI2C.
*
*   Second string:
*    RD: xx xx AA BB
*       RD:- Data being read by I2C Mater from EZI2C.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/
#include <project.h>
#include <device.h>

/* Slave address of the EZI2C */
#define EZI2C_SLAVE_ADDR        (0x08u)
#define BUFFER_SIZE             (0x04u)
#define BUFFER_RW_AREA_SIZE     (0x02u)

/* Denotes the offset inside the EZI2C buffer */
#define SLAVE_ADDR_SIZE         (0x01u)

#define ACTION_SELECT_NONE      (0x00u)     /* Do nothing       */
#define ACTION_SELECT_WRITE     (0x01u)     /* Write to EZI2C   */
#define ACTION_SELECT_READ      (0x02u)     /* Read from EZI2C  */

/* Desing interrupt handlers for SW1 and SW2 event */
CY_ISR_PROTO(ISR_WriteSW1_Interrupt);
CY_ISR_PROTO(ISR_ReadSW2_Interrupt);

/* EZI2C buffer */
uint8   ezi2cBuffer[BUFFER_SIZE];

/* I2C buffer with the data read from EZI2C */
uint8   i2cBufferRead[BUFFER_SIZE];

/* I2C buffer with the data to be written to EZI2C */
uint8   i2cBufferWrite[SLAVE_ADDR_SIZE + BUFFER_SIZE];

/* Initialize action variable */
volatile uint8 actionSelect = ACTION_SELECT_NONE;
 uint8 MyArray[512];

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1. Enables global interrupts
*   2. Starts Character LCD and print usage info
*   3. Starts EZI2C and I2C Master components
*   4. Enable I2C master interrupts
*   5. Sets initial value to the read only area in the EZI2C buffer
*   6. Configures EZI2C buffer
*   7. In the infinite loop checks for the 'actionSelect' variable and execute
*      selected action (write to the ECI2C(SW1 was pressed) or read from it (SW2
*      was pressed))
*
*   Writes to the EZI2C (SW1 was pressed):
*   8. Clears action variable ('actionSelect')
*   9. Increments I2C write buffer values.
*   10. Clears I2C Master status, writes data to the slave device (EZI2C) and
*       waits write to be completed.
*   11. Displays data to be written to the EZI2C.
*
*   Reads from the EZI2C (SW2 was pressed):
*   12. Clears action variable ('actionSelect')
*   13. Clears I2C Master status, reads data from the slave device (EZI2C) and
*       waits read operation to be completed.
*   14. Displays data read from the EZI2C buffer.
*
*   The pin interrupt request bit is cleared and corresponding action is set to
*   'actionSelect' in the ISR_Read.c  and ISR_Write.c files.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main()
{
    //uint8 i;

    /* Start Character LCD and display usage info */
    LCD_Start();
    LCD_Position(0u, 0u);
    LCD_PrintString("SW1 to Write");
    LCD_Position(1u, 0u);
    LCD_PrintString("SW2 to Read ");

    /* Start I2C UDB Master*/

    /* Start EZI2C (customizer's settings will be applied) */
    EZI2C_Start();

    /* Start ISRs */


    /* Enable global interrupts */
    CyGlobalIntEnable;

    /* Initialize EZI2C buffer's read only data */
    ezi2cBuffer[BUFFER_RW_AREA_SIZE     ] = 0xAAu;
    ezi2cBuffer[BUFFER_RW_AREA_SIZE + 1u] = 0xBBu;

    /***************************************************************************
    * The first parameter sets the size of the exposed memory to the I2C
    * interface. In this case, it is the entire array. The second parameter sets
    * the boundary between the read/write and read only areas by setting the
    * number of bytes in the read/write area. The read/write area is first,
    * followed by the read only area. In this case, only the first
    * BUFFER_RW_AREA_SIZE bytes may be written, but all bytes may be read by the
    * I2C master. The third parameter is a pointer to the data.
    ***************************************************************************/
    EZI2C_SetBuffer1(sizeof(MyArray), 512, (void *) MyArray);

    for(;;)
    {
        if((EZI2C_GetActivity()&EZI2C_STATUS_WRITE1)==1){
            LCD_Position(0,0);
            LCD_PrintString("Esta escribiendo");
            MyArray[0]=5;
            if((EZI2C_GetActivity()&EZI2C_STATUS_READ1)==1){
                LCD_Position(1,0);
                LCD_PrintString("Esta leyendo");
            }
        }
    }
}
