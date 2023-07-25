#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c, char buffer[], int *index);
int print_string(const char *str, char buffer[], int *index);
#endif /* MAIN_H */

