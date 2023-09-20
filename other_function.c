#include "main.h"
#include <stdio.h>

/**
 * rev_string - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */
char *rev_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
		;

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * write_base - sends characters to be written on standard output
 * @str: String to parse
 */
void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * base_len - Calculates the length for an octal number
 * @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 * Return: An integer representing the length of a number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * _memcpy - copy memory area
 * @dest: Destination for copying
 * @src: Source to copy from
 * @n: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * print_buffer - print a buffer's content if it exist
 * @buffer: arrays of characters
 * @buff_ind: the buffer index
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * print_hexa_char - Prints a character in hexadecimal format
 * @c: The character to be printed
 * Return: The number of characters printed
 */
int print_hexa_char(char c)
{
	char hex_digits[] = "0123456789ABCDEF";
	int count = 0;

	_putchar(hex_digits[(c >> 4) & 0xF]);
	_putchar(hex_digits[c & 0xF]);
	count += 2;

	return (count);
}


/**
 * _puts - function that print a string
 *
 * @str: string to be printed
 * Return: length.
 */

int _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * convert - Convert an unsigned long integer to a specified base as a string.
 * @num: The number to convert.
 * @base: The base for conversion (e.g., 16 for hexadecimal).
 * @uppercase: Whether to use uppercase letters for hexadecimal
 *
 * Return: A dynamically allocated string containing the converted number.
 */
char *convert(unsigned long int num, int base, int uppercase)
{
	char buffer[64];
	char *result;
	int i = 0;
	int j = 0;
	char *hex_chars;

	if (uppercase)
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";


	if (num == 0)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}

	while (num > 0)
	{
		buffer[i++] = hex_chars[num % base];
		num /= base;
	}

	result = malloc(i + 1);
	if (!result)
		return (NULL);


	for (j = 0; i > 0; j++, i--)

		result[j] = buffer[i - 1];
	result[j] = '\0';

	return (result);
}

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CHR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CHR[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CHR[j])
			{
				flags = FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CHR[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
