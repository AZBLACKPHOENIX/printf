#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * handle_precision - Handle precision for various specifiers
 * @format: The format string
 * @args: Argument list containing the value to be printed
 * @printed_chars: Pointer to the count of printed characters
 */
void handle_precision(const char *format, va_list args, int *printed_chars)
{
    int precision = -1;
    char specifier = *format;
    char buffer[100];
    int len = 0;
int padding = 0;
int i = 0;
    if (*format == '.')
    {
        format++;
        precision = 0;
        while (*format >= '0' && *format <= '9')
        {
            precision = precision * 10 + (*format - '0');
            format++;
        }
    }
    switch (specifier)
    {
        case 'd':
        case 'i':
            len = snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));
            break;
        case 'u':
            len = snprintf(buffer, sizeof(buffer), "%u", va_arg(args, unsigned int));
            break;
        case 'o':
            len = snprintf(buffer, sizeof(buffer), "%o", va_arg(args, unsigned int));
            break;
        case 'x':
        case 'X':
            len = snprintf(buffer, sizeof(buffer), (specifier == 'x') ? "%x" : "%X", va_arg(args, unsigned int));
            break;
        case 'b':
            len = snprintf(buffer, sizeof(buffer), "%s", decimal_to_binary(va_arg(args, unsigned int)));
            break;
        case 'p':
            len = snprintf(buffer, sizeof(buffer), "%p", va_arg(args, void *));
            break;
        default:
            break;
    }
    padding = (precision > len) ? precision - len : 0;
    for (i = 0; i < padding; i++)
    {
        putchar('0');
        (*printed_chars)++;
    }
    for (i = 0; i < len; i++)
    {
        putchar(buffer[i]);
        (*printed_chars)++;
    }
}

