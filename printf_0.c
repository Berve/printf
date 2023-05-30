#include "main.h"


/**
 * _printf - function that produces output according to a format.
 * @format: format which is a character string.
 * The format string is composed of zero or more directives
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char character;

	va_start(args, format);
	
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				character = (char)va_arg(args, int);
				putchar(character);
				count++;
			}
			else if (*format == 's')
			{
				char *string_ = va_arg(args, char *);

				while (*string_ != '\0')
				{
					putchar(*string_);
					string_++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
			else
			{
				putchar (*format);
				count++;
			}
			format++;
	}

	va_end(args);

	return count;
}
