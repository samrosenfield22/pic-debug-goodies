/* 
 * File:   libc.h
 * Author: swg
 *
 * Created on April 8, 2018, 4:14 AM
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
  
void dprintstr(const unsigned char *);
void dprintnum(int);
void dprintf(const char *, ...);

//void dputchar(unsigned char);



#ifdef	__cplusplus
}
#endif

#endif	/* LIBC_H */

