#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Print formatted output according to a format string.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	char current_char;

	while ((current_char = *format))
	{
		if (current_char == '%')
		{
			format++; // Move past '%'

			// Check the next character after '%'
			switch (*format)
			{
				case 'd':
				case 'i':
				{
					// Print a signed decimal integer
					int num = va_arg(args, int);
					count += print_number(num);
					break;
				}
				default:
				{
					// Unsupported conversion specifier, print the character as is
					putchar('%');
					putchar(*format);
					count += 2;
					break;
				}
			}
		}
		else
		{
			// Regular character, print as is
			putchar(current_char);
			count++;
		}

		format++; // Move to the next character in the format string
	}

	va_end(args);
	return count;
}

/**
 * print_number - Print a signed decimal integer.
 * @num: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	unsigned int abs_num;
	int count = 0;

	if (num < 0)
	{
		putchar('-');
		abs_num = -num;
		count++;
	}
	else
	{
		abs_num = num;
	}

	if (abs_num / 10 != 0)
		count += print_number(abs_num / 10);

	putchar('0' + (abs_num % 10));
	count++;

	return count;
}

int main()
{
	int num = 42;
	char letter = 'A';
	char name[] = "Alice";

	_printf("Number: %d, Letter: %c, Name: %s\n", num, letter, name);
	_printf("The value of pi is approximately %d\n", 3);

	return 0;
}

