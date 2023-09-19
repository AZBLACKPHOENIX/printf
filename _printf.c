#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
int value = 0;
	char *str;
char c;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                value = va_arg(args, int);
                printed_chars += printf("%d", value);
            }
            else if (*format == 's')
            {
                str = va_arg(args, char *);
                if (str != NULL)
                {
                    printed_chars += printf("%s", str);
                }
                else
                {
                    printed_chars += printf("(null)");
                }
            }
            else if (*format == 'c')
            {
                c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            
	    }
            else
            {
                putchar('%');
                printed_chars++;
                putchar(*format);
                printed_chars++;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);
    return printed_chars;
}
