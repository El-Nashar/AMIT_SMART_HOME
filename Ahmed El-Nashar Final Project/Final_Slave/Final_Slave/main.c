

#include "LED.h"
#include "SPI.h"
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
   		uint8 Received_Data ;
   		uint8 Trans_Data;
   		
   		LED0_Init();
		LED1_Init();
		LED2_Init();
		
   		SPI_SlaveInit();
   	
   		
   		while (1)
   		{
	   		
	   		Received_Data = SPI_Rec();
	   		
	   	switch (Received_Data)
	   	{
	   	    case '1':
		    LED0_ON();
	   		break;
			   
			case '2':
			LED0_OFF();
			break;
			 
	        case '3':
		    LED1_ON();
		    break;
			  
		    case '4':
		    LED1_OFF();
		    break;
			  
	        case '5':
		    LED2_ON();
       	    break;
			   
		    case '6':
		    LED2_OFF();
	 	    break;
			 
			 case '7':
			 LED0_ON();
			 LED1_ON();
			 LED2_ON();
			 break;
			 
			  case '8':
			  LED0_OFF();
			  LED1_OFF();
			  LED2_OFF();
			  break;
			  
			  case '9':
			  LED_Alarm();
			  break;
			  
			  default:
			  break;
	   	}
	   		
			   
			   
			   
		 /*if(Received_Data == '1')
	   		{
		   		DIO_WritePin(DIO_PORTD ,DIO_PIN0, DIO_PIN_HIGH);
		   		//Received_Data = 0;
	   		}
	   		
			else if(Received_Data == '2')
			{
				DIO_WritePin(DIO_PORTD ,DIO_PIN0, DIO_PIN_LOW);
				//Received_Data = 0;
			}
			
			else if(Received_Data == '3')
			{
				DIO_TogglePin(DIO_PORTD ,DIO_PIN2);
				//Received_Data = 0;
			}*/
	   		
   		}
}

