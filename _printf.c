#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Our custom printf function
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
                    char c = va_arg(args, int); // Treat char as int argument
                    write(1, &c, 1);
                    count++;
                }
                break;
                case 's':
                {
                    const char *s = va_arg(args, const char *);
                    int length = 0;
                    while (s[length])
                        length++;
                    write(1, s, length);
                    count += length;
                }
                break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, "%", 1);
                    count++;
                    write(1, format, 1);
                    count++;
                    break;
            }
        }
        else
        {
            write(1, format, 1);count++;
}
format++;
}
va_end(args);
return count;
}
