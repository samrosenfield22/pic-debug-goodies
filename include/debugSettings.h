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
#define USING_SOFT_UART
  
//********************   soft UART port settings   ********************//
//define the port pin for the uart debug port
#define SOFTUARTDIR (TRISAbits.TRISA0)
#define SOFTUARTPIN (LATAbits.LATA0)
  
//calculate this -- it should be FOSC/baud, where FOSC is the oscillator
//frequency and baud is the desired baud rate
//note that DELAYVAL must be less than 32767
#define DELAYVAL	(1667)
									


#ifdef	__cplusplus
}
#endif

#endif	/* DEBUGSETTINGS_H */

