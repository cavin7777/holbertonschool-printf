#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - A simplified printf function
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;

		for (i = 0; format[i] != '\0'; i++)

		{
			if (format[i] != '%')
				putchar(format[i]);

		}
		return (0);
}


int main(void)
{
	int printed = _printf("Hello, Lucas!!!!!!\n");

	return (0);
}
