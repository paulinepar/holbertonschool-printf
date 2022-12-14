#include "main.h"
/**
 * _printf - print function
 * @format: format
 * Return:(i)
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int j;
	int i = 0;

	if (!format || !strcmp(format, "%"))
	{
		return (-1);
	}
	va_start(arguments, format);

	j = 0;
	while (format[j])
	{
		if ((format[j + 1] == 0 || format[j + 1] == '%') && format[j] == '%')
		{
			putchar('%');
			j++;
			i++;
		}
		else if (format[j] == '%')
		{
			i += get_func(arguments, format[j + 1]);
			j++;
		}
		else
		{
			i += 1;
			putchar(format[j]);
		}
		j++;
	}
	va_end(arguments);
	return (i);
}
