#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

#define DD_MISO    PB3

#define DD_MOSI    PB2

#define DD_SCK     PB1

#define DD_SS      PB0

#define DDR_SPI    DDRB

void SPI_MasterInit(void)

{

	// Set MOSI and SCK output, all others input

	DDR_SPI |= (1<<DD_MOSI)|(1<<DD_SCK) |(1<<DD_SS);

	// Enable SPI, Master, set clock rate fck/16

	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);

}

uint8_t SPI_MasterTransmit(char cData)

{



	SPDR = cData;



	while(!(SPSR & (1<<SPIF)));

	return(SPDR);

}

int main(void) {

	SPI_MasterInit();



	while(1)
	
	 {
	 	SPI_MasterTransmit('A');
	 	_delay_ms(100);
	 	SPI_MasterTransmit('B');
	 	_delay_ms(100);
	 }


}



