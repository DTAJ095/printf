#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @sp: character that holds the flag specifier
 * @fl: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char sp, flags_t *fl)
{
    int i = 0;

    switch (sp)
    {
    case '+':
        fl->plus = 1;
        i = 1;
        break;
    case ' ':
        fl->space = 1;
        i = 1;
        break;
    case '#':
        fl->hash = 1;
        i = 1;
        break;
    }
    return (i);
}
