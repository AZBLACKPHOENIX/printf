#include "main.h"
#include <stdio.h>

int main()
{
char c = 'A';
char *str = "Hello, World!";
int percent = 42;
_printf("%c\n", c);
_printf("%s\n", str);
_printf("%%\n", percent);
return 0;
} 
