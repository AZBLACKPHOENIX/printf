#include "main.h"

/**
 * handle_print - handles the printing of conversion specifiers
 * @format: format string
 * @args: va_list containing the arguments to be printed
 * @count: pointer to count of characters printed
 * Return: 0 on success, -1 on error
 */
int handle_print(const char *format, va_list args, int *count)
{
    int i = 0;
    char size;
    int width;
    int precision;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            size = get_size(format, &i);
            width = get_width(format, &i);
            precision = get_precision(format, &i);

            switch (format[i])
            {
                case 'c':
                    print_char(args, count);
                    break;
                case 's':
                    print_string(args, count);
                    break;
                case '%':
                    print_percent(count);
                    break;
                case 'd':
                case 'i':
                    print_integer(args, count, size, width, precision);
                    break;
                case 'u':
                    print_unsigned(args, count, size, width, precision);
                    break;
                case 'x':
                    print_hexa(args, count, size, width, precision);
                    break;
                case 'X':
                    print_hexa_upper(args, count, size, width, precision);
                    break;
                case 'o':
                    print_octal(args, count, size, width, precision);
                    break;
                case 'p':
                    print_pointer(args, count);
                    break;
                case 'b':
                    print_binary(args, count);
                    break;
                case 'R':
                    print_rot13_string(args, count);
                    break;
                case 'r':
                    print_reverse(args, count);
                    break;
                case 'N':
                    print_non_printable(args, count);
                    break;
                default:
                    _putchar(format[i]);
                    (*count)++;
            }
        }
        else
        {
            _putchar(format[i]);
            (*count)++;
        }
        i++;
    }

    return 0;
}

