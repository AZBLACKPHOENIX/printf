#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

/* Prototypes for functions handling different conversion specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_unsigned_integer(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int print_binary(va_list args);
int print_pointer(va_list args);
int print_custom_s(va_list args);
int print_custom_r(va_list args);
int print_custom_R(va_list args);

/* Prototypes for functions handling flag characters */
int handle_plus_flag(int value, int *printed_chars);
int handle_space_flag(int value, int *printed_chars);
int handle_hash_flag(int value, int *printed_chars);
int handle_zero_flag(int value, int *printed_chars);
int handle_minus_flag(int value, int *printed_chars);

/* Prototypes for functions handling length modifiers */
int handle_length_modifier_l(va_list args, char specifier);
int handle_length_modifier_h(va_list args, char specifier);

/* Prototypes for functions handling width and precision */
int handle_width(const char *format, int *index, va_list args);
int handle_precision(const char *format, int *index, va_list args);

#endif /* MAIN_H */

