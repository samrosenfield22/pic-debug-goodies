

#include "../include/softUart.h"


//softUartSetup() is currently defined as a macro -- if it ends up doing more than just
//clearing the SOFTUARTDIR TRIS bit, we'll add this back in
/*void softUartSetup()
{
	SOFTUARTDIR = 0b0;
}*/

//dputchar() is an alias for softUartWriteChar
void softUartWriteChar(char byte)
{ 
	softUartWriteBit(0b0);	//start bit
	for(unsigned char i=1; i; i<<=1)	//index through the bits
	{
		softUartWriteBit((byte&i)? 0b1 : 0b0);
	}
	softUartWriteBit(0b1);	//stop bit / leave line high
	//softUartWriteBit(0b1);
 }

static void softUartWriteBit(bool sendBit)
{
	//set the pin voltage to the given logic level
	SOFTUARTPIN = sendBit;
	
	//delay
	for(short i=DELAYVAL; i>0; i--);
}
