#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) 
{
    va_list args;
    int count = 0;
    char c;
    char *str;
    int num;
    char *unknown;
va_start(args, format);
    while (*format != '\0') 
    {
        if (*format == '%') 
	{
            format++;
            if (*format == 'c') 
	    {
                c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's') 
	    {
              str = va_arg(args, char*);
                while (*str != '\0')
		{
                    putchar(*str);
                    count++;
                    str++;
                }
            }
            else if (*format == 'd' || *format == 'i') 
	    {
               num = va_arg(args, int);
                printf("%d", num);
                count++;
            }
	      else if (*format == 'r')
	      {
                unknown = "Unknown";
                while (*unknown != '\0') {
                    putchar(*unknown);
                    count++;
                    unknown++;
                }
	      }
            else if (*format == '%') 
	    {
                putchar('%');
                count++;
            }
        } else 
	{
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
