#include "main.h"

/**
 * parser - produces a formated string according to necessary paramters
 * and the main string
 * @format: the format
 * @func_list: the list of all possible functions
 * @arg_list: the list of all arguments passed to the program
 * @buffer: array of characters
 *
 * Return: the total count printed characters
 */

int parser(const char *format, conver_t func_list[], va_list arg_list, char buffer[])
{
	int i = 0, j = 0, val, printed_char = 0, printed = 0;
	int buff_ind = 0;

	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (; func_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == func_list[j].sym[0])
				{
					val = func_list[j].func(arg_list);
					if (val == -1)
						return (-1);
					printed_char += val;
					break;
				}
			}
			if (func_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					/*_putchar(format[i]);
					_putchar(format[i + 1]);*/
					print_buffer(buffer, &buff_ind);
					printed = parser(format, func_list, arg_list, buffer);
					printed_char += printed;
				}
				else
					return (-1);
			}
			i += 1;
		}
		else
		{
			/*_putchar(format[i]);*/
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_char++;
		}
	}
	return (printed_char);
}
