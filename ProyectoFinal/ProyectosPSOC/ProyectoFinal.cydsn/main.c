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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
uint8 get_width(uint8 volt);
uint8 Potential,Width,LCD_OutputString, contador,true,delay;
uint16 	TimeDistMeas 	= 0;					// Value read from TimeDistMeas, eg HC-SRO4 PW returned, in 1 uS increments
float 	distmeas 		= 0.0;					// Value measured, uS / 148 = inches
char 	dispbuff[ 20 ];	
uint16 TimeDistMeas2    = 0;
float   distmeas2        = 0.0;
int mov = 0;
char mensaje;
void ServoMotor();
void UltraSonidos();
int width = 0;
int mueve =1;
int sensibilidad = 5;
float lecturas1[11], lecturas2[11];
int i = 0;
int ya_toma = 0;
uint8 pasa_posicion(float grados);
//void mueve_ar_killo();
void envia_mensaje();
void coloca_muestreo();
void accion_mensaje(char mensajeS);
int signal;
uint8 MyArray[512];
int main()
{
	CYGlobalIntEnable;
//	Clock_1_Enable();
//	Clock_2_Enable();
	true =1;
	contador =5;
	delay = 200;
 ADC_Start();
 LCD_Start();
 LCD_Position(0,0);
 LCD_PrintString("Sensibilidad:");
 LCD_Position(0,14);
 LCD_PrintInt8(sensibilidad);
//	CyGlobalIntEnable; /* Enable global interrupts. */
TimeDistMeas_Start( ); 
	/* Place your initialization/startup code here (e.g. MyInst_Start()) */

	for(;;)
	{
		/* Place your application code here. */
		//ServoMotor();
		//if(toma_Read()==1)
			UltraSonidos();
            
		
				ADC_StartConvert();
 ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
 Potential=ADC_GetResult8();
 width = get_width(Potential);
 if((width <25) && (width > 5)){
	sensibilidad = width;
}
 LCD_Position(0,14);
 LCD_PrintInt8(sensibilidad);
//        mueve_ar_killo();
	}
}
/*
void ServoMotor()
{
	ADC_StartConvert();
 ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
 Potential=ADC_GetResult8();
 delay= 1000;
if (mueve){
	if((contador>=5)&(contador<=25)){
	if( true==1){
		Width= contador++;
		CyDelay(delay);
	}
	else{
		Width= contador--;
		CyDelay(delay);
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
}

 if((Width >9)&( Width <20)) LCD_OutputString= Width +6;
 else if (Width >19) LCD_OutputString= Width +12;
 else LCD_OutputString= Width;

 LCD_Position(0,10);
 LCD_PrintInt8(LCD_OutputString);
 PWM_WriteCompare(Width);

 }
*/
void UltraSonidos()
{
		while( DistOutHCSRO4_Read( ) == 0 ) { 					// HC-SRO4 ready for a trigger, to start new measurement cycle ?
			
			Triggen_Write( 1 ); 								// Trigger the HC-SRO4 to issue the 10 uS start pulse, and reset TimeDistMeas
			CyDelayUs( 10 );									// Trigger high for 10 uS
			Triggen_Write( 0 );									// Remove trigger and reset from TimeDistMeas
			CyDelay( 1 );										// Delay 1 mS to see if HC-SRO4 started a measurement, if not issue another trigger to HC-SRO4
			
		}
		while( DistOutHCSRO4_Read( ) == 1 ) { };				// Wait until HC-SRO4 finishes measurement cycle

		TimeDistMeas = 65535 - TimeDistMeas_ReadCounter( );		// Get timer value, PW in uS, of HC-SRO4
		distmeas = (float) TimeDistMeas / 148.0;
		if (ya_toma){
			if ((distmeas<lecturas1[i]-sensibilidad)||(distmeas>lecturas1[i]+sensibilidad)){
				foto_Write(1);
 //               ya_toma = 0;
			}
			else if ((distmeas2<lecturas2[i]-sensibilidad)||(distmeas2<lecturas2[i]+sensibilidad)){
				foto_Write(1);
//                ya_toma = 0;
			}
		}
		else{
			lecturas1[i]=distmeas;
			lecturas2[i]=distmeas2;
		}
		if(i>10){
			mueve++;
			i=0;
			if(mueve == 5){
				ya_toma = 1;
			}
		}
		else{
			i++;
		}
//        foto_Write(0);
		


		//sprintf( dispbuff, "%.2f", distmeas );					// Convert distmeas to a string to print on LCD
/*		sprintf( dispbuff, "%d", (int)distmeas );					// Convert distmeas to a string to print on LCD
		LCD_Position( 0, 11 );									// Position cursor
		LCD_PrintString( dispbuff );
*/
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
//else return 10;
}
/*
uint8 pasa_posicion(float grados){
	uint8 posicion;
	posicion = (uint8) (grados/180 * 25);
	posicion += 5;
	if(posicion>25)posicion=25;
	return posicion;
}
*/
/*
void mueve_ar_killo(){
	if (mov!=0){
		if(mov==1){contador--;i--;}
		else if(mov==2){contador++;i++;}
	}
}*/

/* [] END OF FILE */
