#include "main.h"

/**
*_printf - implementation of the inbuilt printf
*@format: the format specifier
*Return: the formated string
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
while (*format)
{
if (*format == '%' && format[1])
{
format++;
if (*format == 'c' || *format == 's' || *format == '%')
count += (*format == 'c') ? _putchar(va_arg(args, int)) :
(*format == 's') ? custom_puts(va_arg(args, char *)) :
_putchar('%');
}
else
{
count += _putchar(*format);
}
format++;
}
va_end(args);
return (count);
}
