#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format
 *
 * Return: the total count of the printed characters
 */

int _printf(const char *format, ...)
{
	int printed_char;
	char buffer[BUFF_SIZE];
	conver_t func_list[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", binary},
		{"u", unsigned_int},
		{"o", octal},
		{"x", hexa},
		{"X", HEXA}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);

	printed_char = parser(format, func_list, arg_list, buffer);

	va_end(arg_list);

	return (printed_char);
}
