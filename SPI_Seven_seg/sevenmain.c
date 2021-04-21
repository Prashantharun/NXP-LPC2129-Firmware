#include <LPC21xx.H>

void spi_init(void);
void spi_transmit(unsigned short x);
void max7219_init(void);

//*********************************************************************//

int main(void)
{
	spi_init();
	
	max7219_init();
	
	/* Start the data transmission */
	
	spi_transmit(0x0101);      // Segement digit 1 : 1 displayed
	
	spi_transmit(0x0202);      // Segement digit 2 : 2 displayed
	
	spi_transmit(0x0303);      // Segement digit 3 : 3 displayed

	spi_transmit(0x0404);      // Segement digit 4 : 4 displayed

}

//********************************************************************//

void spi_init(void)
{
	/* Set the Pin function to SPI0 mode 
	   P0.4 -> SCLK
     P0.5 -> MISO
     P0.6 -> MOSI	
	*/
	PINSEL0 = 0x00001500;
	
	/* GPIO pin for seleting Slave - P0.7*/
	IO0DIR |= (1<<7);
  
	/* SPI control register 
	   3 -> Clock phase
	   4 -> Clock polarity
	   5 -> Master/Slave mode
 	*/
	S0SPCR = (1<<2)| (1<<3) | (1<<4) | (1<<5);
	
	/* SPI Clock Counter register
	   8 selected
	*/
	S0SPCCR = 8;
	
	/* By default pulled high Slave select pin */
	IOSET0 = (1 << 7);
}

//*****************************************************************************//

void spi_transmit(unsigned short x)
{
	IOCLR0 = (1<<7);              // Pull to Zero to initiate start of transmisstion in SPI
	S0SPDR = x;                   // Start of communication
	while(!(S0SPSR & (1<<7)));    // Wait till transmission
	IOSET0 = (1 << 7);		        // Disable SPI communication with the slave
}

//*****************************************************************************//

void max7219_init(void)
{
	spi_transmit(0x0C01);        // Shutdown register : Normal operation
	
	spi_transmit(0x0A0F);        // Intensity register : Max
	
	spi_transmit(0x090F);        // Decode register : D0, D1, D2, D3 digits
	
	spi_transmit(0X0B03);        // Scan limit register :  0 1 2 3 segment digits 
}

//******************************************************************************//