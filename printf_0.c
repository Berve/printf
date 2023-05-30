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

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
				count += print_char(args);

			else if (*format == 's')
				count += print_string(args);

			else if (*format == '%')
			{
				putchar('%');
				count++;
			}

			else
			{
				putchar ('%');
				count++;
				putchar(*format);
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

	return (count);
}

int print_char(va_list args)
{
    char character = (char)va_arg(args, int);
    putchar(character);
    return (1);
}

int print_string(va_list args)
{
    char *string_ = va_arg(args, char *);
    int count = 0;

    while (*string_ != '\0')
    {
        putchar(*string_);
        string_++;
        count++;
    }

    return (count);
}
