#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_rot13_string - prints a ROT13 encoded string
 * @args: va_list containing the string to print
 * @count: pointer to count of characters printed
 */
void print_rot13_string(va_list args, int *count)
{
    const char *s = va_arg(args, const char *);
    char c;
    while (*s)
    {
        c = rot13(*s);
        _putchar(c);
        (*count)++;
        s++;
    }
}

/**
 * rot13 - encodes a character using ROT13
 * @c: character to encode
 * Return: ROT13 encoded character
 */
char rot13(char c)
{
    if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
        return c + 13;
    else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
        return c - 13;
    else
        return c;
}

/**
 * print_reverse - prints a reversed string
 * @args: va_list containing the string to reverse and print
 * @count: pointer to count of characters printed
 */
void print_reverse(va_list args, int *count)
{
    const char *s = va_arg(args, const char *);
    int length = 0;
    while (s[length])
        length++;

    for (int i = length - 1; i >= 0; i--)
    {
        _putchar(s[i]);
        (*count)++;
    }
}

/**
 * print_pointer - prints a pointer's address in hexadecimal
 * @args: va_list containing the pointer to print
 * @count: pointer to count of characters printed
 */
void print_pointer(va_list args, int *count)
{
    void *ptr = va_arg(args, void *);
    unsigned long int num = (unsigned long int)ptr;
    _putchar('0');
    _putchar('x');
    *count += 2 + print_hexadecimal_address(num);
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
 * print_non_printable - prints non-printable characters as escaped sequences
 * @args: va_list containing the string to print
 * @count: pointer to count of characters printed
 */
void print_non_printable(va_list args, int *count)
{
    const char *s = va_arg(args, const char *);
    while (*s)
    {
        if (*s < 32 || *s >= 127)
        {
            *count += 2;
            _putchar('\\');
            _putchar(*s + '0');
        }
        else
        {
            _putchar(*s);
            (*count)++;
        }
        s++;
    }
}
