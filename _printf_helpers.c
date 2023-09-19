#include "main.h"

/* Helper function to handle the '+' flag character */
int handle_plus_flag(int value, int *printed_chars)
{
    if (value >= 0)
    {
        putchar('+');
        (*printed_chars)++;
    }
    return 0;
}

/* Helper function to handle the ' ' (space) flag character */
int handle_space_flag(int value, int *printed_chars)
{
    if (value >= 0)
    {
        putchar(' ');
        (*printed_chars)++;
    }
    return 0;
}

/* Helper function to handle the '#' flag character */
int handle_hash_flag(int value, int *printed_chars)

    if (value >= 0)
    {
        putchar('#');
        (*printed_chars)++;
    }
    return 0;
}

/* Helper function to handle the '0' flag character */
int handle_zero_flag(int value, int *printed_chars)
{
   
    if (value >= 0)
    {
        putchar('0');
        (*printed_chars)++;
    }
    return 0;
}

/* Helper function to handle the '-' flag character */
int handle_minus_flag(int value, int *printed_chars)
{
    if (value >= 0)
    {
        putchar('-');
        (*printed_chars)++;
    }
    return 0;
}
/* Helper function to print a binary representation of an unsigned integer */
int print_binary(va_list args)
{
      unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int i = 0;
    int bit = 0;
    int num_bits = sizeof(unsigned int) * 8;
    unsigned int bitmask = 1 << (num_bits - 1);
        for (int i = 0; i < num_bits; i++) 
	{
        int bit = (num & bitmask) ? 1 : 0;
        putchar('0' + bit);
        bitmask >>= 1;
        count++;
        if (count % 4 == 0 && count != num_bits)
            putchar(' ');
    }
    putchar('\n');
    return count;
}

/* Helper function to print a reversed string */
int print_custom_r(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
      int length = strlen(str);
int i = 0;
    for (i = length - 1; i >= 0; i--) 
    {
        putchar(str[i]);
        count++;
    }
    return count;
}

/* Helper function to print a rot13'ed string */
int print_custom_R(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
int i = 0;
char c = str[i];
 for (i = 0; str[i] != '\0'; i++) 
 {
        if (isupper(c)) 
	{
            c = 'A' + ((c - 'A' + 13) % 26);
        }
        else if (islower(c)) 
	{
            c = 'a' + ((c - 'a' + 13) % 26);
        }
        putchar(c);
        count++;
    }
    putchar('\n');
    
    return count;
}
