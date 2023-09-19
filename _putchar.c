#include "main.h"

/**
* _printf - Custom implementation of the printf function
* @format: The format specifier
* Return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list arg_list;
va_start(arg_list, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
printed_chars = custom_selector(format, arg_list, printed_chars);
format++;
}
else
{
_putchar(*format);
printed_chars++;
format++;
}
}
va_end(arg_list);
return (printed_chars);
}

/**
* custom_selector - Process and print a custom format specifier
* @format: The format specifier
* @args: The argument list
* @count: The current count of printed characters
* Return: The updated count of printed characters
*/
int custom_selector(const char *format, va_list args, int count)
{
if (*format == 'c')
{
char ch = va_arg(args, int);
_putchar(ch);
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
count += custom_puts(str);
}
else if (*format == '%')
{
_putchar('%');
count++;
}
return (count);
}
/**
* custom_puts - Print a custom string and return the number of characters printed
* @str: The string to print
* Return: The number of characters printed
*/
int custom_puts(char *str)
{
int i = 0;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
return (i);
}

