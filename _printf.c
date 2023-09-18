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
    char c = va_args(args, int);
    int length= 0;
    const char *s = va_arg(args, const char *);
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
                    write(1, &c, 1);
                    count++;
                }
                break;
                case 's':
                {
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
