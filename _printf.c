#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char c;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                case 's':
                    printed_chars += _print_str(va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
 case 'd':
                case 'i':
                    printed_chars += _print_int(va_arg(args, int));
break;
                default:
                    putchar('%');
                    putchar(*format);
                    printed_chars += 2;
                    break;
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
    return (printed_chars);
}

int _print_str(char *str)
{
    int i = 0;

    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        putchar(str[i]);
        i++;
    }

    return (i);
}

int _print_int(int n)
{
    int len = 0;
    int divisor = 1;

    if (n < 0)
    {
        putchar('-');
        len++;
        divisor = -divisor;
    }

    while (n / divisor > 9 || n / divisor < -9)
        divisor *= 10;

    while (divisor != 0)
    {
        putchar((n / divisor) % 10 + '0');
        len++;
        divisor /= 10;
    }

    return (len);
}
