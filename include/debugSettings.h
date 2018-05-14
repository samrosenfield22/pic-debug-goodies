/* 
 configuration settings for the pic-debug-goodies library
 */

#ifndef DEBUGSETTINGS_H
#define	DEBUGSETTINGS_H

#ifdef	__cplusplus
extern "C"
{
#endif

//********************   assertion settings   ********************//
//uncomment this to disable all assertions
//#define NDEBUG
  
//comment this out if there is no software uart/debug port
//upon failed assertions, instead of printing to the debug port, the failure
//condition, file name and line number will be stored in variables so that they
//can be viewed using the debugger
#define USING_SOFT_UART
  
//********************   soft UART settings   ********************//
//define the port pin for the uart debug port
//#define SOFTUARTDIR (TRISAbits.TRISA0)
//#define SOFTUARTPIN (LATAbits.LATA0)
#define SOFTUARTDIR (TRISBbits.TRISB0)
#define SOFTUARTPIN (LATBbits.LATB0)
  
//calculate DELAYVAL using the following formula:
//FOSC / (baud * clksperinstruction * 18)
//where
//FOSC is the system oscillator
//baud is the desired baud rate
//clksperinstruction is the number of clock cycles per instruction cycle -- ex. for most PIC16s, this
//is 4. this can typically be found near the beginning of the "Instruction Set Summary" chapter of the datasheet
//18 is (roughly) the number of instructions executed for every UART bit
//ex for a 16MHz system freq, baud rate of 9600 symbols/sec, 4 cycles per instruction: DELAYVAL = 23
//note that DELAYVAL must not be greater than 32767
#define DELAYVAL 23
									


#ifdef	__cplusplus
}
#endif

#endif	/* DEBUGSETTINGS_H */

