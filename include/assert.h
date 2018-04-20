/* 
 */

#ifndef ASSERT_H
#define	ASSERT_H

#ifdef	__cplusplus
extern "C"
{
#endif


#include <xc.h>
#include <string.h>
  
#include "debugSettings.h"
  
#ifdef USING_SOFT_UART
	#include "dlibc.h"
#endif

//function prototypes
void assertionFailure(const char *, const char *, unsigned long);
void assertResetCondition(void);

//definition of the assert() macro function -- if NDEBUG is defined, assert() does nothing
#ifndef NDEBUG
	#define assert(expr) \
    if (expr) ; \
    else assertionFailure(#expr, __FILE__, __LINE__)
#else
	#define assert(expr)	//do nothing
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* ASSERT_H */

