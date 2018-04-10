

#include "../include/softUart.h"

void softUartSetup()
{
	SOFTUARTDIR = 0b0;
}

/*void softUartWriteString(const unsigned char *str)
{
	for(; *str; str++)
		softUartWriteChar(*str);
}*/

//putch() is automatically called by printf()
void softUartWriteChar(unsigned char byte)
{
	softUartWriteBit(0b0);	//start bit
	for(unsigned char i=1; i; i<<=1)	//index through the bits
	{
		(byte&i)? softUartWriteBit(true) : softUartWriteBit(false);
	}
	softUartWriteBit(0b1);	//stop bit / leave line high
}

void softUartWriteBit(bool sendBit)
{
	//set the pin voltage to the given logic level
	SOFTUARTPIN = sendBit;
	
	//delay
	for(unsigned long i=0; i<DELAYVAL; i++);
}



///////////////////////////////////////////////////////////////////////////////


/*

#include "../include/softUart.h"

//unsigned short softUartDelay;

//FOSC must be defined somewhere (in this example, it's in system.h)
void softUartSetup(unsigned long baud)
{
	SOFTUARTDIR = 0b0;
	
	//calculate delay counter value
	//softUartDelay = FOSC/baud;
	//softUartDelay = (FOSC>>16)*7;
	
//#ifndef DELAYVAL
//#error "delayval not defined!"
	
	//n/3 = 
	//fosc = 20000000
	//fosc/baud = 2083
	//(fosc>>16)*7 = 2135
}

//putch() is automatically called by printf()
void putch(unsigned char byte)
//{
//	softUartWriteChar(byte);
//}

//void softUartWriteChar(unsigned char byte)
{
	softUartWriteBit(0b0);	//start bit
	for(unsigned char i=1; i; i<<=1)	//index through the bits
	{
		(byte&i)? softUartWriteBit(true) : softUartWriteBit(false);
	}
	
	softUartWriteBit(0b1);	//stop bit / leave line high
}

void softUartWriteBit(bool sendBit)
{
	
	//set the pin voltage to the given logic level
	SOFTUARTPIN = sendBit;
	
	//delay
	//for(unsigned short i=0; i<softUartDelay; i++);
	for(unsigned long i=0; i<DELAYVAL; i++);
}
*/