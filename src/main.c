/*
 pic-debug-goodies
 PIC code for easy debugging
 Written by Sam Rosenfield
 */

#include <xc.h>

#include "../include/assert.h"
#include "../include/dlibc.h"

void main(void)
{
	//if the internal oscillator is being used, the oscillator frequency must be
	//set before using the software UART
	//ex.
	OSCCONbits.IRCF = 0b1111;	//16MHz
	
	//if a soft UART debugging port is being used, this should be called before
	//assertResetCondition so that failed assertions can be printed to the terminal
	//(note that this sets the TRIS bit of the soft UART port, so setting it manually
	//is not required)
	softUartSetup();
	
	//check bits in the reset module to verify that the pic did not reset due
	//to a error condition (such as a stack overflow)
	assertResetCondition();
	
	//application code begins here!
	dputs("\r\nstarting execution...\r\n");
	while(1)
	{
		
	}
	
	return;
}
