#include "main.h"
#include <stdio.h>

/**
 * binary - converts a number from base 10 to binary
 * @list: the list of arguments
 * Return: lenght of the printed number
 */

int binary(va_list list)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * octal - Prints a number in octal base
 * @list: List of arguments
 * Return: Number of symbols printed to stdout
 */
int octal(va_list list)
{
	unsigned int num;
	int len;
	char *oct;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	oct = malloc(sizeof(char) * len + 1);
	if (oct == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		oct[len] = (num % 8) + 48;
		num = num / 8;

	}
	oct[len] = '\0';
	rev_str = rev_string(oct);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(oct);
	free(rev_str);
	return (len);
}

/**
 * hexa - Converts a decimal number to base16 lowercase
 * @list: List of the arguments
 * Return: Number of characters printed
 */
int hexa(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex = malloc(sizeof(char) * len + 1);
	if (hex == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = check_hex(rem_num, 'x');
			hex[len] = rem_num;
		}
		else
			hex[len] = rem_num + 48;
		num = num / 16;
	}
	hex[len] = '\0';
	rev_hex = rev_string(hex);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex);
	free(rev_hex);
	return (len);
}

/**
 * HEXA - Convert a decimal number to base16 Uppercase
 * @list: List of the arguments
 * Return: Number of characters printed
 */
int HEXA(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex = malloc(sizeof(char) * len + 1);
	if (hex == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = check_hex(rem_num, 'X');
			hex[len] = rem_num;
		}
		else
			hex[len] = rem_num + 48;
		num = num / 16;
	}
	hex[len] = '\0';
	rev_hex = rev_string(hex);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex);
	free(rev_hex);
	return (len);
}

/**
 * check_hex - Checks which hex function to call
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int check_hex(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
