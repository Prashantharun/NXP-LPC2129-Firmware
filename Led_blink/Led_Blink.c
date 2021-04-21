/*********************************************************************
**	Project Name : LED												**
**  Pin Numbers  : P1.17 to P1.24									**
*********************************************************************/

/* LPC2129 Header File */ 
#include <LPC21xx.H>

#include "led.h"

/* Delay Function */
/* for 12MHz Cloock Frequency it generates = 1ms Delay */
void delay(int count)
{								// Delay Start
	int i,j;					// Variable Declaration
	for(i = 0;i < count;i++)	// Delay Loop
	for(j = 0;j < 1275;j++);	// Delay Loop 
} 								// End of Delay Function

/* Main Function */
int main()
{					   			// Main Starts
	LED_Init();	// LED Initialization
	while(1)		   			// Infinite Loop
	{							// While open
		IOSET1 = (1<<17) | (1<<24);		// LED's ON
		delay(1000);			// Delay
		IOCLR1 = (1<<17) | (1<<24);		// LED's OFF
		delay(1000);		// Delay
 	}							// End of While		
}								// End of Start

/********************************************************************
**                         End of File  						   **
********************************************************************/

