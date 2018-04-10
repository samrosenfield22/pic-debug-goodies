/*
 to use the software uart module, the following things must be set up:
 
 * SOFTUARTDIR and SOFTUARTPIN must be defined as the TRIS and LAT fields of the
 pin being used (defined in this file)
 * DELAYVAL must be defined -- it should be set to FOSC/baud (define it in this file)
 * any program wishing to use printf() to send data over the TX line must first call
 softUartSetup()
 * in order for assert() to print debugging, uncomment the #definition of
 USING_SOFT_UART (in assert.h)
 
 */

#ifndef SOFTUART_H
#define	SOFTUART_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include <xc.h>
//#include <stdio.h>
#include <stdbool.h>
  
#include "system.h"
  
//define these!
#define SOFTUARTDIR (TRISAbits.TRISA0)
#define SOFTUARTPIN (LATAbits.LATA0)
  
#define DELAYVAL	(1667)
  
void softUartSetup(void);
//void softUartWriteChar(unsigned char);
//void softUartWriteString(const unsigned char *);
void softUartWriteChar(unsigned char);
void softUartWriteBit(bool);


#ifdef	__cplusplus
}
#endif

#endif	/* SOFTUART_H */

