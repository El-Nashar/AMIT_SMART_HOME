
#include "UART.h"
#include "SPI.h"
#define  F_CPU  8000000
#include <util/delay.h>

int main(void)
{
	uint8 Received_Data ;
	
	
	DIO_SetPinDir(DIO_PORTA ,DIO_PIN0 , DIO_PIN_OUTPUT);
	
	UART_Init();
	SPI_MasterInit();
	SPI_InitTrans();
	_delay_ms(1000);
   
    while (1) 
    {
		Received_Data = UART_Recive_Byte();
		
		if (Received_Data)
		{
			DIO_WritePin(PORTA, DIO_PIN0, DIO_PIN_HIGH);
			
		}
		DIO_WritePin(PORTA, DIO_PIN0, DIO_PIN_LOW);
		SPI_Trans(Received_Data);
		
		
    }
}

