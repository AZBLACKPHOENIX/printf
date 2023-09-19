#include "main.h"

/**
 * get_precision - extracts the precision value from a format string
 * @format: format string
 * @start: index in the format string where the precision is expected
 * Return: extracted precision value
 */
int get_precision(const char *format, int *start)
{
    int precision = 0;
    int i = *start;
    if (format[i] != '.')
        return -1;
    i++;
    while (format[i] >= '0' && format[i] <= '9')
    {
        precision = precision * 10 + (format[i] - '0');
        i++;
    }
    if (i == *start + 1)
        return -2;
    *start = i;
    return precision;
}
