#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello, %s! You are %c%% amazing.\n", "world", '5');
    _printf("Number of characters printed: %d\n", len);

    len = _printf("Printing integers: %d, %i\n", 42, -123);
    _printf("Number of characters printed: %d\n", len);

    len = _printf("Printing unsigned integers: %u\n", 12345);
    _printf("Number of characters printed: %d\n", len);

    len = _printf("Printing octal numbers: %o\n", 255);
    _printf("Number of characters printed: %d\n", len);

    len = _printf("Printing hexadecimal numbers: %x and %X\n", 255, 255);
    _printf("Number of characters printed: %d\n", len);

    return (0);
}
