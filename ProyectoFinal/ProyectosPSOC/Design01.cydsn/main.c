/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Char_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Char_1_Position(0,0);
    //LCD_Char_1_PrintString("Hola");
    for(;;)
    {
        if(Entrada_Read()==1){
            LCD_Char_1_PrintString("Hola");
            while(1);
        }
    }
}

/* [] END OF FILE */
