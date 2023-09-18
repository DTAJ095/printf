#include "main.h"

/**
 * print_char - prints character
 * @list: list of arguments
 * Return: the character printed
 */
int print_char(va_list list)
{
	char chr = va_arg(list, int);

	_putchar(chr);
	return (-1);
}

/**
 * print_str - prints a string
 * @list: the list of arguments
 * Return: the total count of printed string
 */
int print_str(va_list list)
{
	int i = 0;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - prints the percentage symbol
 * @list: the list of arguments
 * Return: will return the amount of characters printed
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}
