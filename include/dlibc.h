/* 
 */

#ifndef DLIBC_H
#define	DLIBC_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include <stdarg.h>

#include "softUart.h"

#define dputchar softUartWriteChar
  
//function prototypes
void dputs(const unsigned char *);
void dprintnum(int);
void dprintf(const char *, ...);


#ifdef	__cplusplus
}
#endif

#endif	/* DLIBC_H */

