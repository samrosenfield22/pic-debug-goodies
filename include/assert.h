/* 
 * 
 * take a look at:
 https://nicisdigital.wordpress.com/2011/07/05/assertions-in-microcontrollers/#comment-2329
 */

#ifndef ASSERT_H
#define	ASSERT_H

#ifdef	__cplusplus
extern "C"
{
#endif

//uncomment this to disable assertions
//#define NDEBUG
  
//comment this out if there is no software uart/debug port
#define USING_SOFT_UART

#ifdef USING_SOFT_UART
	#include "libc.h"
#endif

#include <xc.h>
#include <string.h>

  
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

