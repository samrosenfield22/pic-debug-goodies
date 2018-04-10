/* 
 */

#ifndef LIBC_H
#define	LIBC_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include <stdarg.h>

#include "softUart.h"

#define dputchar softUartWriteChar
  
//function prototypes
void dprintstr(const unsigned char *);
void dprintnum(int);
void dprintf(const char *, ...);


#ifdef	__cplusplus
}
#endif

#endif	/* LIBC_H */

