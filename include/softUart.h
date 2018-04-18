/*
 to use the software uart module, the following things must be set up:
 
 * SOFTUARTDIR and SOFTUARTPIN must be defined as the TRIS and LAT fields of the
 pin being used (defined in this file)
 * DELAYVAL must be defined -- it should be set to FOSC/baud (define it in this file)
	* the user is required to calculate this value in order to reduce the softUart's memory overhead
 * any program wishing to use dputchar()/dprintf()/dprintnum() to send data over the TX line must
 first call softUartSetup()
 * in order for assert() to automatically print debugging info, uncomment the #definition of
 USING_SOFT_UART (in assert.h)
 
 */

#ifndef SOFTUART_H
#define	SOFTUART_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include <xc.h>
#include <stdbool.h>
  
//define these!
#define SOFTUARTDIR (TRISAbits.TRISA0)
#define SOFTUARTPIN (LATAbits.LATA0)
#define DELAYVAL	(1667)			//calculate this -- it should be FOSC/baud
									//where FOSC is the oscillator frequency, and
									//baud is the desired baud rate
									//note that DELAYVAL must be less than 32767
  
//function prototypes
void softUartSetup(void);
void softUartWriteChar(unsigned char);
void softUartWriteBit(bool);


#ifdef	__cplusplus
}
#endif

#endif	/* SOFTUART_H */

