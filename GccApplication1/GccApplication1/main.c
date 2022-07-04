

#include <avr/io.h>
#include <string.h>
#include "uart.h"

int main(void)
{
	uint8 Str[30];
	uint8 *head;
	uint8 *data;

	/* Initialize the UART driver with Baud-rate = 9600 bits/sec */
	UART_init(9600);

	while(1)
	{
		//data = UART_recieveByte(); /* Receive Byte from Terminal1 */
		//UART_sendByte(data);       /* Re-send the received byte to Terminal2 */
		head=UART_receiveString(Str);     /* Receive String from Terminal */
		data=UART_receiveString(Str);
		
		if(data[12] == (uint8)'0' && (data[13] == (uint8)'2')  || (data[13] == (uint8)'3'))
		{
			UART_sendString("Emergency!\r");
		}
		else
		{
			UART_sendString("No Emergency\r");
		}

		   
	}
}
