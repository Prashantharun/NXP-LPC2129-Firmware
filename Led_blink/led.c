/*********************************************************************
**	File Name	 : led.c 											**
**  Pin Numbers  : P1.17 to P1.24									**
*********************************************************************/

/* LPC2129 Header File */ 
#include <LPC21xx.H>

#include "led.h"

void LED_Init(void)
{
	IODIR1 |= LED_ALL;			// Declared as output pin - P1.17 to P1.24
	IOCLR1 |= LED_ALL;	// Clear all LED's
}
/********************************************************************
**                         End of File  						   **
********************************************************************/
