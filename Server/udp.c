void GSM_UDP(char * message, char * ip) {

	PORTB |= (1<<PB0); // LED ON

	UART1_9600_Print("AT+CIICR\r");
	_delay_ms(1000);
	
	UART1_9600_Print("AT+CIPSTART=\"UDP\",\"");
	UART1_9600_Print(ip);
	UART1_9600_Print("\",\"5000\"\r");
	_delay_ms(1000);

	UART1_9600_Print("AT+CIPSEND\r");
	_delay_ms(1000);

	UART1_9600_Print(message);
	UART1_9600_Send((char)26);
	_delay_ms(1000);

	UART1_9600_Print("AT+CIPCLOSE\r");
	_delay_ms(1000);
	UART1_9600_ClearBuffer();

	PORTB &= ~(1<<PB0); // LED OFF
}