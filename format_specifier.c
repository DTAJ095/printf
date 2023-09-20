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

/**
 * unsigned_int - prints an unsigned integer
 * @list: the list of arguments
 * Return: the number
 */
int unsigned_int(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsigned_num(num));
	if (num < 1)
		return (-1);
	return (print_unsigned_num(num));
}

/**
 * print_String - Prints a string with non-printable char
 * @list : the list of arguments
 * Return: The number of characters printed
 */
int print_String(va_list list)
{
	int count = 0;
	int i = 0;
	char *str = va_arg(list, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_hexa_char(str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}

	return (count);
}

/**
 * print_pointer - Prints a memory address in hexadecimal format with "0x" prefix
 * @list: The list of arguments
 * Return: The number of characters printed
 */

int print_pointer(va_list list)
{
	unsigned long int ptr = va_arg(list, unsigned long int);
	char *hexa;
	int count = 0;

	if (ptr == NULL)
	{
		count += _puts("(nil)");
	}
	else
	{
		count += _puts("0x");
		hexa = convert(ptr, 16, 1);
		if (hexa != NULL)
		{
			count += _puts(hexa);
			free(hexa);
		}
		else
		{
			return (-1);
		}
	}

	return (count);
}
