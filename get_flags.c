#include "main.h"

/**
 * get_flags - extracts flags from a format string
 * @format: format string
 * @start: index in the format string where the flags are expected
 * Return: extracted flags as an integer (bitmask)
 */
int get_flags(const char *format, int *start)
{
    int flags = 0;
    int i = *start;

    while (format[i])
    {
        char current = format[i];

        if (current == '-')
            flags |= FLAG_MINUS;
        else if (current == '+')
            flags |= FLAG_PLUS;
        else if (current == ' ')
            flags |= FLAG_SPACE;
        else if (current == '0')
            flags |= FLAG_ZERO;
        else if (current == '#')
            flags |= FLAG_HASH;
        else
            break;
        i++;
    }
    *start = i;
    return flags;
}
