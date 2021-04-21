/* LPC2129 Header File */ 
#include <LPC21xx.H>

#define SW   (0<<25) 

#define LED  (1<<17)

void Switchinit(void);


int main()
{
	Switchinit();
	
	while(1)
	{
	   if(IOPIN1 & SW)
		 {
			 IOSET1|= LED;
		 }
		 else
		 {
			 IOCLR1|= LED;
		 }
	}
	
	
}

void Switchinit(void)
{
	IODIR1 |= 0x01FE0000;
	IOCLR1 |= 0x01FE0000;
	IODIR1 |= SW ;
	IODIR1 |= LED;
}