#include "main.h"

/**
 * get_width - extracts the width value from a format string
 * @format: format string
 * @start: index in the format string where the width is expected
 * Return: extracted width value
 */
int get_width(const char *format, int *start)
{
    int width = 0;
    int i = *start;

    while (format[i] >= '0' && format[i] <= '9')
    {
        width = width * 10 + (format[i] - '0');
        i++;
    }

    *start = i;
    return width;
}
