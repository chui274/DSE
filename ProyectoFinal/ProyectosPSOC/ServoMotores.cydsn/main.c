/* ========================================
 *
 * Copyright PSoC 3 LABBOOK
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION BELONGING TO
 * ADITYA YADAV
 * ASHWATH KRISHNAN
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
uint8 get_width(uint8 volt);
void main()
{
uint8 Potential,Width,LCD_OutputString, contador,true,delay;
    true =1;
    contador =5;
    delay = 200;
 Clock_Enable();
 PWM_Start();
 ADC_Start();
 LCD_Start();
 LCD_Position(0,0);
 LCD_PrintString("Servo Pos:");
for(;;)
 {
 ADC_StartConvert();
 ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
 Potential=ADC_GetResult8();
 delay= get_width(Potential);
if(contador>=5&contador<=25){
    if( true==1){
        Width= contador++;
        CyDelay(delay*10);
    }
    else{
        Width= contador--;
        CyDelay(delay*10);
    }
}
else if (contador>25){
    true=0;
    contador--;
}
else{
    true=1;
    contador++;
}

 if((Width >9)&( Width <20)) LCD_OutputString= Width +6;
 else if (Width >19) LCD_OutputString= Width +12;
 else LCD_OutputString= Width;

 LCD_Position(0,10);
 LCD_PrintInt8(LCD_OutputString);
 PWM_WriteCompare(Width);

 }
}
uint8 get_width(uint8 volt)
{
if (volt<0x0C) return 5; //12 0x0C
else if (volt<0x19) return 6; //25 0x19
else if (volt<0x26) return 7; //38 0x26 
else if (volt<0x32) return 8; //50 0x32
else if (volt<0x3e) return 9; //62 0x3e
else if (volt<0x4B) return 10; //75 0x4b
else if (volt<0x57) return 11; //87 0x57
else if (volt<0x64) return 12; //100 0x64
else if (volt<0x70) return 13; //112 0x70
else if (volt<0x7D) return 14; //125 0x7d
else if (volt<0x89) return 15; //137 0x89
else if (volt<0x96) return 16; //150 0x96
else if (volt<0xA2) return 17; //162 0xA2
else if (volt<0xAF) return 18; //175 0xAF
else if (volt<0xBB) return 19; //187 0xBB
else if (volt<0xC8) return 20; //200 0xC8
else if (volt<0xD4) return 21; //212 0xD4
else if (volt<0xE1) return 22; //225 0xE1
else if (volt<0xED) return 23; //237 0xED
else if (volt<0xFA) return 24; //250 0xFA
else if (volt>0xFA) return 25; //250 0xFA
}
/* [] END OF FILE */ 