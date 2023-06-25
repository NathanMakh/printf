#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
void print_number(int n);

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
#endif
