#include "main.h"

/**
*_printf -  inbuilt printf
*@format: format specifier
*Return:  formated string
*/
int _printf(const char *format, ...)
{
int i, work;
int (*f)(va_list);
va_list list;
if (format == NULL)
return (-1);
va_start(list, format);
i = work = 0;
while (format[i] != '\0')
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
return (-1);
f = get_func(format[i + 1]);
if (f == NULL)
work += print_nan(format[i], format[i + 1]);
else
work += f(list);
i++;
}
else
{
_putchar(format[i]);
work++;
}
i++;
}
va_end(list);
return (work);
}
