#include "main.h"

/**
 * print_string - loops through a string and prints
 * every character until end of string character 
 * @li: va_list arguments from _printf
 * @fl: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_string(va_list li, flags_t *fl)
{
    char *s = va_arg(li, char *);

    (void)fl;

    if (!s)
        s = "(null)";
    return (_puts(s));
}

/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_char(va_list li, flags_t *fl)
{
    (void)fl;
    _putchar(va_arg(li, int));
    return (1);
}
