/*
 */



#include <xc.h>

#include "../include/assert.h"
#include "../include/dlibc.h"


void main(void)
{
  
	//if a soft UART debugging port is being used, this should be called before
	//assertResetCondition so that failed assertions can be printed to the terminal
	softUartSetup();
	
	//check bits in the reset module to verify that the pic did not reset due
	//to a error condition (such as a stack overflow)
	assertResetCondition();
	
	//application code begins here!
	
	
	return;
}
