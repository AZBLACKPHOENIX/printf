#include "main.h"
#include <stdlib.h>

/**
 * print_binary - Print an unsigned integer in binary format
 * @args: Argument list containing the unsigned integer
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
  char binary[32]; 
        int index = 0;
	int i;
    if (num == 0)
    {
        count++;
    }
    else
    {
        while (num > 0)
        {
            binary[index++] = (num % 2) + '0';
            num /= 2;
        }

        for (i = index - 1; i >= 0; i--)
        {
            putchar(binary[i]);
            count++;
        }
    }

    return count;
}

/**
 * print_custom_S - Print a string with non-printable characters as \x followed by ASCII code
 * @args: Argument list containing the string
 * Return: Number of characters printed
 */
int print_custom_S(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
   unsigned char hex_digits[2];
  char *null_str; 
  int i = 0; 
  int j = 0;
  unsigned char ascii_code = str[i];
  if (str == NULL)
    {
       null_str = "(null)";
        for (i = 0; null_str[i] != '\0'; i++)
        {
            putchar(null_str[i]);
            count++;
        }
        return count;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            putchar('\\');
            count++;
            putchar('x');
            count++;
            hex_digits[0] = (ascii_code >> 4) & 0xF;
            hex_digits[1] = ascii_code & 0xF;

            for (j = 0; j < 2; j++)
            {
                if (hex_digits[j] < 10)
                {
                    putchar(hex_digits[j] + '0');
                    count++;
                }
                else
                {
                    putchar(hex_digits[j] - 10 + 'A');
                    count++;
                }
            }
        }
        else
        {
            putchar(str[i]);
            count++;
        }
    }

    return count;
}

/**
 * print_custom_p - Print a pointer address
 * @args: Argument list containing the pointer
 * Return: Number of characters printed
 */
int print_custom_p(va_list args)
{
    void *ptr = va_arg(args, void *);
    int count = 0;
    unsigned long int address = (unsigned long int)ptr;
    int num_digits = 0;
int digit;
int i = 0;
char hex_digits;
    while (address > 0)
    {
        address >>= 4;
        num_digits++;
    }

    if (num_digits == 0)
    {
        putchar('0');
        count++;
    }
    else
    {
        address = (unsigned long int)ptr;
        for (i = num_digits - 1; i >= 0; i--)
        {
            digit = address & 0xF;
            if (digit < 10)
            {
                hex_digits[i] = digit + '0';
            }
            else
            {
                hex_digits[i] = digit - 10 + 'a';
            }
            address >>= 4;
        }
        for (i = 0; i < num_digits; i++)
        {
            putchar(hex_digits[i]);
            count++;
        }
    }

    return count;
}

/**
 * print_custom_r - Print a reversed string
 * @args: Argument list containing the string
 * Return: Number of characters printed
 */
int print_custom_r(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
char *null_str;
int i;
int length = 0;
    if (str == NULL)
    {
        null_str = "(null)";
        for (i = 0; null_str[i] != '\0'; i++)
        {
            putchar(null_str[i]);
            count++;
        }
        return count;
    }
    for (length = 0; str[length] != '\0'; length++)
        {
    for (i = length - 1; i >= 0; i--)
    {
        putchar(str[i]);
        count++;
    }

    return count;
}

/**
 * print_custom_R - Print a rot13'ed string
 * @args: Argument list containing the string
 * Return: Number of characters printed
 */
int print_custom_R(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
char *null_str;
int i;
char c;
    if (str == NULL)
    {
        null_str = "(null)";
        for (i = 0; null_str[i] != '\0'; i++)
        {
            putchar(null_str[i]);
            count++;
        }
        return count;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        c = str[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
            {
                c += 13;
            }
            else
            {
                c -= 13;
            }
        }

        putchar(c);
        count++;
    }

    return count;
}
