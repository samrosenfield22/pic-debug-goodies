

#include "../include/assert.h"


/*
 This function is called when assert() fails. 
 */
void assertionFailure(const char *condition, const char *file, unsigned long line)
{	
	//disable all interrupts
	GIE = 0b0;
	
	
	//volatile const char *dCondition = condition;
	//volatile const char *dFile = file;
	
	
	//display ...
	#ifdef USING_SOFT_UART
		//dprintf("Failed assertion: %s\nin file %s, line %d\n", condition, file, line);
		dprintstr("Failed assertion: ");
		dprintstr(condition);
		dprintstr("\nin file ");
		dprintstr(file);
		dprintstr(", line ");
		dprintnum(line);
		dputchar('\n');
	#else
		//collect debugging information to view from the variables console
		volatile unsigned long dLine = line;
		volatile char dCondition[24];
		volatile char dFile[16];

		memset(dCondition, 0, sizeof(dCondition));
		memset(dFile, 0, sizeof(dFile));
		strncpy(dCondition, condition, sizeof(dCondition)-1);
		strncpy(dFile, file, sizeof(dFile)-1);
	#endif
	
	//add code here to indicate that an assertion failure occurred
	//(ex. light a LED or something)
	
	//add a backtrace here, if possible
	//
	
	//halt execution
	//if the debugger gets stuck here, check the values of dCondition, dLine
	//and dFile for diagnostic information
	//(Window->Debugging->Variables)
	while(1);
}

/*
 Put this at the beginning of your main() function -- if the MCU reset due to a
 problematic reset condition (such as a stack overflow), this will catch it
 */
void assertResetCondition()
{
	assert(!PCONbits.STKOVF);	//a stack overflow reset occurred
	assert(!PCONbits.STKUNF);	//a stack underflow reset occurred
	assert(PCONbits.nRWDT);		//a watchdog timer reset occurred
	//assert(PCONbits.nBOR);		//a brown-out reset occurred
}
