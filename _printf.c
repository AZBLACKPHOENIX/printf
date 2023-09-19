#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    _putchar(c);
                    count++;
                }
                break;
                case 's':
                {
                    const char *s = va_arg(args, const char *);
                    while (*s)
                    {
                        _putchar(*s);
                        s++;
                        count++;
                    }
                }
                break;
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    count++;
                    _putchar(*format);
                    count++;
                    break;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
