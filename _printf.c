#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written.
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - Writes a string to stdout.
 * @str: The string to be written.
 *
 * Return: The number of characters written.
 */

int _putstr(const char *str)
{
	int count = 0;
	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}

/**
 * _putnum - Prints a number to stdout.
 * @num: The number to be printed.
 * @base: The base for conversion (e.g., 10 for decimal, 2 for binary)
 *
 * Return: The number of digits printed.
 */
int _putnum(unsigned int num, unsigned int base)
{
	static const char *digits = "0123456789ABCDEF";
	int count = 0;
	char buffer[1024];
	int i;

	if (num == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	i = sizeof(buffer) - 1;
	buffer[i] = '\0';

	while (num)
	{
		buffer[--i] = digits[num % base];
		num /= base;
	}

	count = _putstr(&buffer[i]);

	return (count);
}

/**
 * _printf - Prints output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr != '%')
		{
			_putchar(*ptr);
			count++;
		}
		else
		{
			ptr++;
			if (*ptr == '%')
			{
				_putchar(*ptr);
				count++;
			}
			else if (*ptr == 'c')
			{
				char c = (char)va_arg(args, int);
				_putchar(c);

				count++;
			}
			else if (*ptr == 's')
			{
				char *str = va_arg(args, char *);
				count += _putstr(str);
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				int num = va_arg(args, int);
				if (num < 0)
				{
					_putchar('-');
					count++;
					num *= -1;
				}
				count += _putnum(num, 10);
			}
			else if (*ptr == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += _putnum(num, 10);
			}
			else if (*ptr == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += _putnum(num, 8);
			}
			else if (*ptr == 'x')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += _putnum(num, 16);
			}
			else if (*ptr == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += _putnum(num, 16);
			}
			else if (*ptr == 'S')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					if (*str < 32 || *str >= 127)
					{
						_putchar('\\');
						_putchar('x');
						count += 2;
						count += _putnum(*str, 16);
					}
					else
					{
						_putchar(*str);
						count++;
					}
					str++;
				}
			}
		}
	}

	va_end(args);

	return (count);
}
