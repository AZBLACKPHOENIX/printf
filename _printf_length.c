#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * handle_length_modifier - Handle length modifiers for 'd' and 'i' specifiers
 * @format: The format string
 * @args: Argument list containing the value to be printed
 * @printed_chars: Pointer to the count of printed characters
 */
void handle_length_modifier(const char *format, va_list args, int *printed_chars)
{
int length_modifier = 0;
int value = 0;
int i = 0;
    while (*format == 'l' || *format == 'h')
    {
        if (*format == 'l')
        {
            length_modifier++;
        }
        else if (*format == 'h')
        {
            length_modifier--;
        }
        format++;
    }
    if (*format == 'd' || *format == 'i')
    {
        if (length_modifier == 0)
        {
            value = va_arg(args, int);
        }
        else if (length_modifier == 1)
        {
            value = va_arg(args, long int);
        }
        else if (length_modifier == -1)
        {
            value = (short int)va_arg(args, int);
       }
        for (i = 0; i < len; i++)
        {
            putchar(buffer[i]);
            (*printed_chars)++;
      }
    }
}
