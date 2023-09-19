#include "main.h"

/**
* my_printf - Custom implementation of printf
* @fmt: the format specifier
* Return: the number of characters printed
*/
int my_printf(const char *fmt, ...)
{
int count = 0;
va_list args;
va_start(args, fmt);
while (*fmt)
{
if (*fmt == '%')
{
fmt++;
count = my_selector(fmt, args, count);
fmt++;
}
else
{
_putchar(*fmt);
count++;
fmt++;
}
}
va_end(args);
return (count);
}
/**
* my_selector - Process and print a custom format specifier
* @fmt: the format specifier
* @args: the argument list
* @count: the current count of printed characters
* Return: the updated count of printed characters
*/
int my_selector(const char *fmt, va_list args, int count)
{
if (*fmt == 'c')
{
char ch = va_arg(args, int);
_putchar(ch);
count++;
}
else if (*fmt == 's')
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
count += my_puts(str);
}
else if (*fmt == '%')
{
_putchar('%');
count++;
}
return (count);
}
/**
* my_puts - Print a custom string and return the number of characters printed
* @str: the string to print
* Return: the number of characters printed
*/
int my_puts(char *str)
{
int i = 0;
while (str && str[i])
{
_putchar(str[i]);
i++;
}
return (i);
}

