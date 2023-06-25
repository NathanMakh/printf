#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: number of characters printed excluding null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				count++;
				break;
			case 's':
				count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
				break;
			case '%':
				write(1, "%", 1);
				count++;
				break;
			default:
				break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
