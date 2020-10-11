
#include  "SPI.h"


void SPI_MasterInit(void)
{
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN4 , DIO_PIN_OUTPUT);
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN5 , DIO_PIN_OUTPUT);
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN6 , DIO_PIN_INPUT);
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN7 , DIO_PIN_OUTPUT);
	 
	SPI->SPCR.SPR0 = 1;
	SPI->SPCR.SPR1 = 1;
	SPI->SPCR.CPHA = 0;
	SPI->SPCR.CPOL = 0;
	SPI->SPCR.MSTR = 1;
	SPI->SPCR.DORD = 0;
	SPI->SPCR.SPE  = 1;	 
}

void SPI_SlaveInit(void)
{
		 DIO_SetPinDir(DIO_PORTB ,DIO_PIN4 , DIO_PIN_INPUT);
		 DIO_SetPinDir(DIO_PORTB ,DIO_PIN5 , DIO_PIN_INPUT);
		 DIO_SetPinDir(DIO_PORTB ,DIO_PIN6 , DIO_PIN_OUTPUT);
		 DIO_SetPinDir(DIO_PORTB ,DIO_PIN7 , DIO_PIN_INPUT);
		 
		SPI->SPCR.SPR0 = 0;
		SPI->SPCR.SPR1 = 0;
		SPI->SPCR.CPHA = 0;
		SPI->SPCR.CPOL = 0;
		SPI->SPCR.MSTR = 0;
		SPI->SPCR.DORD = 0;
		SPI->SPCR.SPE  = 1;
		 
}

void SPI_Trans(uint8 tx_data)
{
	SPI->SPDR = tx_data ;
	
	while(GET_BIT(SPI->SPSR , 7)  ==  0);
	
}

uint8 SPI_Rec()
{
	uint8 rec_data;
	
	while(GET_BIT(SPI->SPSR , 7)  ==  0);
	
	rec_data = SPI->SPDR;
	
	return rec_data ;
}


void SPI_InitTrans(void)
{
	DIO_WritePin(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_LOW);
}

void SPI_TermTrans(void)
{
	DIO_WritePin(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_HIGH);
}