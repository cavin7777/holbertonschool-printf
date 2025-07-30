#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - A simplified printf function
 * @format: The format string
 * Return: Numbers of characters printed
 */
int _printf(const char *format, ...)
{
	int i;
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s++);
					count++;
				}
			}
			else if (format[i] == '%')
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
		}
	}
	va_end(args);
	return (count);
}
