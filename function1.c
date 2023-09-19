#include "main.h"

/**
 * print_binary - prints an unsigned integer in binary
 * @n: unsigned integer to print in binary
 */
void print_binary(unsigned int n)
{
    if (n / 2 != 0)
        print_binary(n / 2);

    _putchar((n % 2) + '0');
}

/**
 * binary_length - calculates the number of digits in a binary representation
 * @n: integer to count binary digits
 * Return: number of binary digits
 */
int binary_length(unsigned int n)
{
    int length = 0;
    if (n == 0)
        return 1;
    while (n != 0)
    {
        n /= 2;
        length++;
    }
    return length;
}

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

/**
 * print_unsigned - prints an unsigned integer
 * @args: va_list containing the unsigned integer to print
 * @count: pointer to count of characters printed
 */
void print_unsigned(va_list args, int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    print_number(num);
    *count += num_length(num);
}

/**
 * print_hexa - prints a lowercase hexadecimal number
 * @args: va_list containing the hexadecimal number to print
 * @count: pointer to count of characters printed
 */
void print_hexa(va_list args, int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    print_hexadecimal(num, "0123456789abcdef");
    *count += num_length(num);
}

/**
 * print_hexa_upper - prints an uppercase hexadecimal number
 * @args: va_list containing the hexadecimal number to print
 * @count: pointer to count of characters printed
 */
void print_hexa_upper(va_list args, int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    print_hexadecimal(num, "0123456789ABCDEF");
    *count += num_length(num);
}

/**
 * print_hexadecimal - prints a hexadecimal number with a given base
 * @num: the number to print in hexadecimal
 * @base: the base string to use (e.g., "0123456789abcdef" or "0123456789ABCDEF")
 */
void print_hexadecimal(unsigned int num, char *base)
{
    if (num / 16 != 0)
        print_hexadecimal(num / 16, base);

    _putchar(base[num % 16]);
}

/**
 * print_octal - prints an octal number
 * @args: va_list containing the octal number to print
 * @count: pointer to count of characters printed
 */
void print_octal(va_list args, int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    print_octal_number(num);
    *count += num_length(num);
}

/**
 * print_octal_number - prints an octal number
 * @num: the number to print in octal
 */
void print_octal_number(unsigned int num)
{
    if (num / 8 != 0)
        print_octal_number(num / 8);

    _putchar((num % 8) + '0');
}
