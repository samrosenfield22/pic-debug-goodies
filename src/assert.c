

#include "../include/assert.h"


/*
 This function is called when assert() fails. 
 */
static void assertionFailure(const char *condition, const char *file, unsigned long line)
{	
	//disable all interrupts
	GIE = 0b0;
	
	//display/store information about the failed assertion. if soft uart is in use,
	//this will be printed to the debug port; if not, it will be stored in local
	//variables (dLine, dCondition and dFile) to be viewed in MPLABX
	#ifdef USING_SOFT_UART
		//dprintf("Failed assert: %s\r\nfile %s, line %d\r\n", condition, file, line);
		dputs("\r\nFailed assert: ");
		dputs(condition);
		dputs("\r\nfile ");
		dputs(file);
		dputs(", line ");
		dprintnum(line, UNSIGNED);
		dputs("\r\n");
	#else
		//collect debugging information to view from the variables console
		//since the "Variables/watches" viewers don't show dereferenced pointers
		//(why?), this copies the diagnostic strings into arrays to be viewed
		volatile unsigned long dLine = line;
		volatile char dCondition[24];
		volatile char dFile[24];
		
		strncpy(dCondition, condition, sizeof(dCondition)-1);
		strncpy(dFile, file, sizeof(dFile)-1);
		
	#endif
	
	//add code here to indicate that an assertion failure occurred
	//(ex. light a LED or something)
	
	//halt execution
	//if the debugger gets stuck here, and a soft UART debug port is not being
	//used, check the values of dCondition, dLine and dFile for diagnostic information
	//(Window->Debugging->Variables)
		
	//to view a backtrace, go to:
	//Window->PIC Memory Views->Hardware Stack
	//note that this does not show function arguments or local variables, only
	//function names and return addresses
	//(does this only work w the simulator? test it)
	while(1);
}

/*
 Put this at the beginning of your main() function -- if the MCU reset due to a
 problematic reset condition (such as a stack overflow), this will catch it
 */
/*using the bits' aliases alone (i.e. STKOVF) uses less memory than using them in the structs/
 bit-fields (i.e. (PCONbits.STKOVF). is there any difference/problem w doing this?*/
void assertResetCondition()
{
	//check for normal reset conditions
	/*if(!PCONbits.nRMCLR);	//MCLR reset
	{
		//dputs("MCLR reset\r\n");
		PCONbits.nRMCLR = 0b1;
		return;
	}
	if((STATUS==0b00011000) && ((PCON&0b00001100)==0b00001100) && (((~PCON)&0b11000010)==0b11000010))	//power-on reset
	{
		//dputs("POR reset\r\n");
		PCONbits.nPOR = 0b1;
		return;
	}*/
	
	//an erroneous reset condition occurred, dump STATUS and PCON
	//for information on interpreting these results, consult the "reset" chapter for your MCU's datasheet
	dputs("\r\nreset error\r\nSTATUS:\t0b");
	dprintbin(STATUS);
	dputs(" (0x");
	dprinthex(STATUS);
	dputs(")\r\nPCON:\t0b");
	dprintbin(PCON);
	dputs(" (0x");
	dprinthex(PCON);
	dputs(")\r\n");
  
	//check for error reset conditions
	assert(!STKOVF);	//a stack overflow reset occurred
	assert(!STKUNF);	//a stack underflow reset occurred
	assert(nRWDT);		//a watchdog timer reset occurred

	//a brown-out reset occurred
	if(((STATUS&0b00011000)==0b00011000) && ((PCON&0b00001100)==0b00001100) && (!PCONbits.nBOR))
	{
		PCONbits.nBOR = 0b1;
		assert(0);
	}
}
