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
  
#define SIGNED true
#define UNSIGNED false
  
//function prototypes
void dputs(const char *);
void dprintnum(short, bool);
void dprintf(const char *, ...);
void dprintbin(char);
void dprinthex(unsigned char);


#ifdef	__cplusplus
}
#endif

#endif	/* DLIBC_H */

