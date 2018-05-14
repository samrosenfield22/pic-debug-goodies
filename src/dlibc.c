

#include "../include/dlibc.h"

void dputs(const char *str)
{
	for(; *str; str++)
		dputchar(*str);
}

//calling this carries a decent memory penalty -- only use if there's plenty of
//extra space!
void dprintf(const char *fmt, ...)
{
	int i;
	char c;
	char *s;
	
	va_list args;
	va_start(args, fmt);
	
	while(*fmt)
	{
		if(*fmt=='%')
		{
			switch(*(fmt+1))
			{
				case 'd':
					i = va_arg(args, int);
					dprintnum(i, SIGNED);
					break;
				case 'u':
					i = va_arg(args, int);
					dprintnum(i, UNSIGNED);
					break;
				case 'c':
					c = va_arg(args, int);
					dputchar(c);
					break;
				case 's':
					s = va_arg(args, char*);
					//for(; *s; s++)
					//	dputchar(*s);
					dputs(s);
					break;
				//case 'x':
				//	int x = va_arg(args, int);
					
				//	break;
				case '\0':
					fmt--;	//back up so the next char we point to (after advancing by 2) will be the null
					break;
				default:
					dputchar(*(fmt+1));
					break;
				
				
			}
			
			fmt+=2;
		}
		else
		{
			dputchar(*fmt);
			fmt++;
		}
	}
	
	va_end(args);
}

void dprintnum(short num, bool sign)
{
	unsigned short weight;
	char curDigit;
	bool numberStarted = false;
	
	//if the number is negative, and we're printing it as a signed value,
	//take its 2's complement to invert it
	if(num<0 && sign==SIGNED)
	{
		num = (~num)+1;
		dputchar('-');
	}
	
	
	for(char digits=5; digits; digits--)
	{
		//generate the digit position's weight (ex. 1000)
		weight = 1;
		for(char i=digits-1; i; i--)
			weight = (weight<<3) + (weight<<1);
		
		//determine how many of the weights fit into the number (divide)
		for(curDigit=0; (unsigned short)num>=weight; curDigit++)
			num -= weight;
		
		//print the obtained digit
		if(curDigit)
			numberStarted = true;
		if(numberStarted)
			dputchar(curDigit+'0');
	}
	
	//if no digits were found, it's because the passed value is a zero
	if(!numberStarted)
		dputchar('0');
}

void dprintbin(char data)
{
	for(unsigned char bitmask = 0x80; bitmask; bitmask>>=1)
		dputchar(data&bitmask? '1' : '0');
}

void dprinthex(unsigned char data)
{
	unsigned char nibble = data>>4;
	(nibble<10)? dputchar(nibble+'0') : dputchar(nibble+'A'-0xA);
	nibble = data & 0x0F;
	(nibble<10)? dputchar(nibble+'0') : dputchar(nibble+'A'-0xA);
}

