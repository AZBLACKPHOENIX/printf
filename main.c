#include "main.h"

int main(void)
{
    int len;

    // Testing %c, %s, and %%
    len = _printf("Hello, %s! You are %c%% amazing.\n", "world", '5');
    _printf("Number of characters printed: %d\n", len);

    // Testing %d and %i
    len = _printf("Printing integers: %d, %i\n", 42, -123);
    _printf("Number of characters printed: %d\n", len);

    // Testing %u, %o, %x, and %X
    len = _printf("Unsigned integer: %u\n", 12345);
    _printf("Number of characters printed: %d\n", len);

    len = _printf("Octal representation: %o\n", 255);
    _printf("Number of characters printed: %d\n", len);

    len = _printf("Lowercase hexadecimal: %x\n", 255);
    _printf("Number of characters printed: %d\n", len);

    len = _printf("Uppercase hexadecimal: %X\n", 255);
    _printf("Number of characters printed: %d\n", len);

    // Testing %b (custom conversion specifier)
    len = _printf("Binary representation of %u is: %b\n", 42, 42);
    _printf("Number of characters printed: %d\n", len);

    return (0);
}

