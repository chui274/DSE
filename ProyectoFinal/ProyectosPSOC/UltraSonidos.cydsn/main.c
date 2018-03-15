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
#include <stdlib.h>
#include <stdio.h>

uint16 	TimeDistMeas 	= 0;					// Value read from TimeDistMeas, eg HC-SRO4 PW returned, in 1 uS increments
float 	distmeas 		= 0.0;					// Value measured, uS / 148 = inches
char 	dispbuff[ 20 ];							// Display buffer for strings

int main( void ) {
	
	//uint8 i = 0;								// for index variable
	
CyGlobalIntEnable; 							// Uncomment this line to enable global interrupts.

	TimeDistMeas_Start( );         				// Start up the distance measuring timer, basically ,measure PW of pulse HC-SRO4 generates
/*	LCD_Start( );								// Start LCD module
	LCD_Position( 0, 0 );						// Cursor to Row 0, Col 0
	LCD_PrintString( "Distancia =" ); */
	
    for(;;) {

			
		while( DistOutHCSRO4_Read( ) == 0 ) { 					// HC-SRO4 ready for a trigger, to start new measurement cycle ?
			
			Triggen_Write( 1 ); 								// Trigger the HC-SRO4 to issue the 10 uS start pulse, and reset TimeDistMeas
			CyDelayUs( 10 );									// Trigger high for 10 uS
			Triggen_Write( 0 );									// Remove trigger and reset from TimeDistMeas
			CyDelay( 1 );										// Delay 1 mS to see if HC-SRO4 started a measurement, if not issue another trigger to HC-SRO4
			
		}
		while( DistOutHCSRO4_Read( ) == 1 ) { };				// Wait until HC-SRO4 finishes measurement cycle

		TimeDistMeas = 65535 - TimeDistMeas_ReadCounter( );		// Get timer value, PW in uS, of HC-SRO4
		distmeas = (float) TimeDistMeas / 148.0;				// Compute distance measured
		
        //sprintf( dispbuff, "%.2f", distmeas );					// Convert distmeas to a string to print on LCD
/*		sprintf( dispbuff, "%d", (int)distmeas );					// Convert distmeas to a string to print on LCD
		LCD_Position( 0, 11 );									// Position cursor
		LCD_PrintString( dispbuff );
*/
		CyDelay( 100 );											// Wait 100 mS before triggering the HC-SRO4 module again	

	}
}

/* [] END OF FILE */
