#include "main.h"

/**
 * print_char - prints a character
 * @args: va_list containing the character to print
 * @count: pointer to count of characters printed
 */
void print_char(va_list args, int *count)
{
    char c = va_arg(args, int);
    _putchar(c);
    (*count)++;
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 * @count: pointer to count of characters printed
 */
void print_string(va_list args, int *count)
{
    const char *s = va_arg(args, const char *);
    while (*s)
    {
        _putchar(*s);
        (*count)++;
        s++;
    }
}

/**
 * print_percent - prints a percent symbol
 * @count: pointer to count of characters printed
 */
void print_percent(int *count)
{
    _putchar('%');
    (*count)++;
}

