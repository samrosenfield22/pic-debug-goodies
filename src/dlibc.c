

#include "../include/dlibc.h"

void dputs(const unsigned char *str)
{
	for(; *str; str++)
		dputchar(*str);
}

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
					dprintnum(i);
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

void dprintnum(int num)
{
	char digits[10];
	int lastNum;
	char cnt=0;
	
	//if the number is negative, take its 2's complement to invert it
	if(num<0)
	{
		num = (~num)+1;
		dputchar('-');
	}
	
	//split the number into digits
	do
	{
		lastNum = num;
		
		//divide num by 10
		//multiply num by 2^32/10 (0x1999999A), then divide (shift) by 2^32
		num = ((long long)(num)*0x1999999A)>>32;
		
		//digits[cnt] = lastNum - num*10
		//digits[cnt] = lastNum - ((num<<3) + (num<<1));
		//digits[cnt] = lastNum - (num<<3) + num + num;
		digits[cnt] = lastNum - (num+num+num+num+num+num+num+num+num+num);	//ugly, but amazingly, uses less
									//memory than digits[cnt] = lastNum - ((num<<3) + (num<<1));
		//digits[cnt] = lastNum - 10*num;
		
		cnt++;
	}
	while(num);
	
	//display each digit
	for(cnt--; cnt>=0; cnt--)
		dputchar(digits[cnt]+'0');
	//cnt--;
	/*while(cnt>=0)
	  {
		dputchar(digits[cnt]+'0');
		cnt--;
	  }*/
	/*while(cnt>0)
	  {
		//cnt--;
		dputchar(digits[--cnt]+'0');
	  }*/
}


