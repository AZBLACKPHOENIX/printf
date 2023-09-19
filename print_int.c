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
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                    {
                        _putchar('-');
                        count++;
                        num = -num;
                    }
                    print_number(num);
                    count += num_length(num);
                }
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

/**
 * print_number - prints an integer recursively
 * @n: integer to print
 */
void print_number(int n)
{
    if (n / 10 != 0)
        print_number(n / 10);

    _putchar((n % 10) + '0');
}

/**
 * num_length - calculates the number of digits in an integer
 * @n: integer to count digits
 * Return: number of digits
 */
int num_length(int n)
{
    int length = 0;
    if (n == 0)
        return 1;
    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return length;
}

