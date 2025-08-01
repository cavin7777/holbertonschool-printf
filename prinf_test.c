#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
					s = "(null)";

				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int n = va_arg(args, int);
				char buf[20];
				int j = 0;
				int neg = 0;

				if (n == 0)
				{
					write(1, "0", 1);
					count++;
				}
				else
				{
					if (n < 0)
					{
						neg = 1;
						n = -n;
					}

					while (n > 0)
					{
						buf[j++] = (n % 10) + '0';
						n /= 10;
					}

					if (neg)
					{
						buf[j++] = '-';
					}

					while (j--)
					{
						write(1, &buf[j], 1);
						count++;
					}
				}
			}
			else if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else
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
