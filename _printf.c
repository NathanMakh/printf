#include <stdarg.h>
#include <unistd.h>
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

	if (num / base)
		count += _putnum(num / base, base);

	_putchar(digits[num % base]);
	count++;

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

				while (*str)
				{
					_putchar(*str);
					count++;
					str++;
				}
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
			else if (*ptr == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += _putnum(num, 2);
			}
		}
	}

	va_end(args);

	return (count);
}
