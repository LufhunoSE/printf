#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Print a single character to stdout.
 * @c: The character to be printed.
 *
 * Return: Number of characters printed (always 1).
 */
int print(char c)
{
    putchar(c);
    return (1);
}

/**
 * print_string - Print a string to stdout.
 * @str: The string to be printed.
 *
 * Return: Number of characters printed.
 */
int print(const char *str)
{
    int count = 0;
    while (*str)
    {
        putchar(*str);
        str++;
        count++;
    }
    return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += print_char(va_arg(args, int));
                    break;

                case 's':
                    count += print_string(va_arg(args, const char *));
                    break;

                case '%':
                    count += print_char('%');
                    break;

                default:
                    count += print_char('%');
                    count += print_char(*format);
            }
        }
        else
        {
            count += print_char(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int num = 65;
    char str[] = "Team work makes the dream work!";

    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", str);
    _printf("Integer: %d\n", num);
    _printf("Percent sign: %%\n");

    return (0);
}
