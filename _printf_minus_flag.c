#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * handle_minus_flag - Handle the '-' flag character for 'd' and 'i' specifiers
 * @format: The format string
 * @args: Argument list containing the value to be printed
 * @printed_chars: Pointer to the count of printed characters
 */
void handle_minus_flag(const char *format, va_list args, int *printed_chars)
{
    int width = 0;
    int value = 0;
    char buffer[20];
    int len = snprintf(buffer, sizeof(buffer), "%d", value);
    while (*format >= '0' && *format <= '9')
    {
        width = width * 10 + (*format - '0');
        format++;
    }

    if (*format == '-')
    {
        format++;
        if (*format == 'd' || *format == 'i')
        {
             value = va_arg(args, int);
            for (i = 0; i < len; i++)
            {
                putchar(buffer[i]);
                (*printed_chars)++;
            }
            padding = width - len;
            for (i = 0; i < padding; i++)
            {
                putchar(' ');
                (*printed_chars)++;
            }
        }
       }
