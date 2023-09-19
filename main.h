#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Flag constants (bitmasks) */
#define FLAG_MINUS  (1 << 0)
#define FLAG_PLUS   (1 << 1)
#define FLAG_SPACE  (1 << 2)
#define FLAG_ZERO   (1 << 3)
#define FLAG_HASH   (1 << 4)

/* Custom printf function */
int _printf(const char *format, ...);

/* Utility functions */
int _putchar(char c);
int num_length(int n);
void print_number(int n);
void print_hexadecimal(unsigned int num, char *base);
int binary_length(unsigned int n);
void print_binary(unsigned int n);
void print_octal_number(unsigned int num);
void print_octal(va_list args, int *count);

/* Flag extraction function */
int get_flags(const char *format, int *start);

/* Other utility functions and types go here if needed */

#endif /* MAIN_H */
