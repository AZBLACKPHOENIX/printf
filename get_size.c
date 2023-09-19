#include "main.h"

/**
 * get_size - extracts the size (length modifier) from a format string
 * @format: format string
 * @start: index in the format string where the size is expected
 * Return: extracted size value
 */
char get_size(const char *format, int *start)
{
    char size = '\0';
    int i = *start;

    switch (format[i])
    {
        case 'h':
        case 'l':
        case 'L':
            size = format[i];
            i++;
            break;
        default:
            return size;
    }
   *start = i;
    return size;
}
