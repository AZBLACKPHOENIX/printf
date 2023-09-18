#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string containing the conversion specifiers
 * @...: The variable number of arguments to print
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's':
                {
                    const char *s = va_arg(args, const char *);
                    if (s)
                    {
                        while (*s)
                        {
                            write(1, s, 1);
                            s++;
                            count++;
                        }
                    }
                    break;
                }
                case 'd':
                {
                    int num = va_arg(args, int);
                    char buffer[32];
 		    int len = snprintf(buffer, sizeof(buffer), "%d", num);
                    write(1, buffer, len);
                    count += len;
                    break;
                }
                default:
                    write(1, format - 1, 1); // Print the '%' character
                    count++;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
