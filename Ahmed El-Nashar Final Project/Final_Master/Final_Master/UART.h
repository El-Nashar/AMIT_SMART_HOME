

#ifndef UART_H_
#define UART_H_

#include "DIO.h"


void UART_Init (void);


void UART_Transmit_Byte(uint8);


uint8 UART_Recive_Byte(void); 




void UART_Transmit_String(uint8 * str);










#endif /* UART_H_ */