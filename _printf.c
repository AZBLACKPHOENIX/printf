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
 case 'o':
                    printed_chars += _print_octal(va_arg(args, unsigned int));
                    break;
	    case 'b':
    printed_chars += _print_binary(va_arg(args, unsigned int));
    break;
    case 'u':
    printed_chars += _print_unsigned(va_arg(args, unsigned int));
    break;
                case 'x':
                    printed_chars += _print_hex(va_arg(args, unsigned int), 0);
                    break;
                case 'X':
                    printed_chars += _print_hex(va_arg(args, unsigned int), 1);
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

int _print_unsigned(unsigned int n)
{
    unsigned int divisor = 1;
    int len = 0;

    if (n == 0)
    {
        putchar('0');
        return (1);
    }

    while (n / divisor > 9)
        divisor *= 10;

    while (divisor != 0)
    {
        putchar((n / divisor) + '0');
        n %= divisor;
        divisor /= 10;
        len++;
    }

    return (len);
}

int _print_octal(unsigned int n)
{
    int octal[100];
    int i = 0;

    if (n == 0)
    {
        putchar('0');
        return (1);
    }

    while (n != 0)
    {
        octal[i] = n % 8;
        n /= 8;
        i++;
    }

    for (i = i - 1; i >= 0; i--)
    {
        putchar(octal[i] + '0');
    }

    return (i + 1);
}

int _print_hex(unsigned int n, int uppercase)
{
    char hex[100];
    int i = 0;
    char *hex_chars = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n == 0)
    {
        putchar('0');
        return (1);
    }

    while (n != 0)
    {
        hex[i] = hex_chars[n % 16];
        n /= 16;
        i++;
    }

    for (i = i - 1; i >= 0; i--)
    {
        putchar(hex[i]);
    }

    return (i + 1);
}

int _print_binary(unsigned int n)
{
    int binary[100];
    int i = 0;

    if (n == 0)
    {
        putchar('0');
        return (1);
    }

    while (n != 0)
    {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }

    for (i = i - 1; i >= 0; i--)
    {
        putchar(binary[i] + '0');
    }

    return (i + 1);
}

