/*
 to use the software uart module, the following things must be set up:
 
 * SOFTUARTDIR and SOFTUARTPIN must be defined as the TRIS and LAT fields of the
 pin being used (defined in debugSettings.h)
 * DELAYVAL must be defined -- it should be set to FOSC/baud (also defined in debugSettings.h)
	* the user is required to calculate this value in order to reduce the softUart's memory overhead
 * any program wishing to use dputchar()/dprintf()/dprintnum() to send data over the TX line must
 first call softUartSetup()
 * in order for assert() to automatically print debugging info, uncomment the #definition of
 USING_SOFT_UART (in debugSettings.h)
 
 */

#ifndef SOFTUART_H
#define	SOFTUART_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include <xc.h>
#include <stdbool.h>
  
#include "debugSettings.h"
  
#define softUartSetup() (SOFTUARTDIR=0b0)
  
//function prototypes
//void softUartSetup(void);
void softUartWriteChar(unsigned char);
void softUartWriteBit(bool);

#ifdef	__cplusplus
}
#endif

#endif	/* SOFTUART_H */

