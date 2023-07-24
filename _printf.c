#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list ourTally;
	va_start(ourTally, format);

	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					int c = va_arg(ourTally, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					const char *str = va_arg(ourTally, const char *);
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(ourTally);
	return (count);
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
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
