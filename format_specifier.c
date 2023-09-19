#include "main.h"

/**
 * print_char - prints character
 * @list: list of arguments
 * Return: the character printed
 */
int print_char(va_list list)
{
	int count;
	char chr = va_arg(list, int);

	count = _putchar(chr);
	return (count);
}

/**
 * print_str - prints a string
 * @list: the list of arguments
 * Return: the total count of printed string
 */
int print_str(va_list list)
{
	int count = 0;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
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

/**
 * print_int - prints integers
 * @list: the list of arguments
 * Return: a number
 */
int print_int(va_list list)
{
	int count;

	count = print_num(list);
	return (count);
}
