#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
 * write_hdlr_char - handler for character type
 * @args: va_list containing the character to print
 * @count: pointer to count of characters printed
 */
void write_hdlr_char(va_list args, int *count)
{
    char c = va_arg(args, int);
    _putchar(c);
    (*count)++;
}

/**
 * write_hdlr_num - handler for integer types (d and i)
 * @args: va_list containing the integer to print
 * @count: pointer to count of characters printed
 * @size: size modifier ('h', 'l', 'L')
 * @width: width specifier
 * @precision: precision specifier
 */
void write_hdlr_num(va_list args, int *count, char size, int width)
{
char format[20];
char buffer[20];
int i = 0;
int n;
    if (size == 'h')
    {
        snprintf(format, sizeof(format), "%%0%dh", width);
    }
    else if (size == 'l')
    {
        snprintf(format, sizeof(format), "%%0%dl", width);
    }
    else if (size == 'L')
    {
        snprintf(format, sizeof(format), "%%0%dl", width);
    }
    else
    {
        snprintf(format, sizeof(format), "%%0%d", width);
    }

    n = va_arg(args, int);
    snprintf(buffer, sizeof(buffer), format, n);
    for ( i = 0; buffer[i] != '\0'; i++)
    {
        _putchar(buffer[i]);
        (*count)++;
    }

}
/**
 * print_hexadecimal_address - prints the hexadecimal representation of a number
 * @num: the number to print in hexadecimal
 * Return: number of characters printed
 */
int print_hexadecimal_address(unsigned long int num)
{
    char *base = "0123456789abcdef";
    if (num / 16 != 0)
        return print_hexadecimal_address(num / 16) + _putchar(base[num % 16]);
    else
        return _putchar(base[num % 16]);
}

/**
 * write_hdlr_ptr - handler for pointer type
 * @args: va_list containing the pointer to print
 * @count: pointer to count of characters printed
 */
void write_hdlr_ptr(va_list args, int *count)
{
    void *ptr = va_arg(args, void *);
    if (ptr == NULL)
    {
  
        char *null_str = "(nil)";
        while (*null_str)
        {
            _putchar(*null_str);
            (*count)++;
            null_str++;
        }
    }
    else
   {
        unsigned long int num = (unsigned long int)ptr;
        _putchar('0');
        _putchar('x');
        (*count) += 2 + print_hexadecimal_address(num);
  }
}
