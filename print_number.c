#include "main.h"

/**
 * print_num - prints a number
 * @arg_list: the list of arguments
 * Return: the number of arguments printed
 */

int print_num(va_list arg_list)
{
	int len, n, div;
	unsigned int num;

	n = va_arg(arg_list, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len = _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}

/**
 * print_unsigned_num - print an unsigned number
 * @n: the unsigned integer to be printed
 * Return: the number printed
 */
int print_unsigned_num(unsigned int n)
{
	int div, len;
	unsigned int num;

	div = 1;
	len = 0;
	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}
