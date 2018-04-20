

#include "../include/assert.h"


/*
 This function is called when assert() fails. 
 */
void assertionFailure(const char *condition, const char *file, unsigned long line)
{	
	//disable all interrupts
	GIE = 0b0;
	
	//display/store information about the failed assertion. if soft uart is in use,
	//this will be printed to the debug port; if not, it will be stored in local
	//variables (dLine, dCondition and dFile) to be viewed in MPLABX
	#ifdef USING_SOFT_UART
		//dprintf("Failed assert: %s\nfile %s, line %d\n", condition, file, line);
		dputs("Failed assert: ");
		dputs(condition);
		dputs("\nfile ");
		dputs(file);
		dputs(", line ");
		dprintnum(line, UNSIGNED);
		dputchar('\n');
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
	//assert(!PCONbits.STKOVF);	//a stack overflow reset occurred
	assert(!STKOVF);
	//assert(!PCONbits.STKUNF);	//a stack underflow reset occurred
	assert(!STKUNF);
	//assert(!(PCON & 0b11000000));
	//assert(PCONbits.nRWDT);		//a watchdog timer reset occurred
	assert(nRWDT);
	//assert(PCONbits.nBOR);		//a brown-out reset occurred
}
