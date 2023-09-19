#include "main.h"

/**
 * is_printable - checks if a character is printable
 * @c: character to check
 * Return: 1 if printable, 0 otherwise
 */
int is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

/**
 * append_hexacode - appends a hexadecimal escape code to a buffer
 * @buffer: buffer to append to
 * @c: character to append
 * @count: pointer to count of characters in buffer
 */
void append_hexacode(char *buffer, char c, int *count)
{
    buffer[(*count)++] = '\\';
    buffer[(*count)++] = 'x';
    buffer[(*count)++] = (c / 16) + '0';
    buffer[(*count)++] = (c % 16) + '0';
}

/**
 * is_digit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * convert_size_usgnd - converts a size character to a format specifier
 * @size: size character (e.g., 'h', 'l', 'L')
 * Return: corresponding format specifier (e.g., 'hh', 'l', 'L') or '\0' if invalid
 */
char convert_size_usgnd(char size)
{
    switch (size)
    {
        case 'h':
            return 'h';
        case 'l':
            return 'l';
        case 'L':
            return 'L';
        default:
            return '\0';
    }
}
