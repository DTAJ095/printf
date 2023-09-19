#include "main.h"

/**
* custom_puts - Print a custom string and return the number of characters printed
* @str: The string to print
* Return: The number of characters printed
*/
int custom_puts(char *str)
{
int i = 0;
while (str && str[i])
{
_putchar(str[i]);
i++;
}
return (i);
}

