#include "main.h"

/**
 * handle_plus_flag - Handle the '+' flag character
 * @value: The value to be printed (integer)
 * @printed_chars: Pointer to the count of printed characters
 */
void handle_plus_flag(int value, int *printed_chars)
{
    if (value >= 0)
    {
        putchar('+');
        (*printed_chars)++;
    }
}

/**
 * handle_space_flag - Handle the ' ' (space) flag character
 * @value: The value to be printed (integer)
 * @printed_chars: Pointer to the count of printed characters
 */
void handle_space_flag(int value, int *printed_chars)
{
    if (value >= 0)
    {
        putchar(' ');
        (*printed_chars)++;
    }
}

/**
 * handle_hash_flag - Handle the '#' flag character
 * @value: The value to be printed (integer)
 * @printed_chars: Pointer to the count of printed characters
 * @specifier: The conversion specifier ('x' or 'X' for hexadecimal)
 */
void handle_hash_flag(int value, int *printed_chars, char specifier)
{
    if (specifier == 'x' || specifier == 'X')
    {
        if (value != 0)
        {
            putchar('0');
            (*printed_chars)++;
            if (specifier == 'x')
            {
                putchar('x');
            }
            else
            {
                putchar('X');
            }
            (*printed_chars)++;
        }
    }
}
