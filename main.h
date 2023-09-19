#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdarg.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

/**
 * struct convert - defines a structure for functions and symbols
 *
 * @sym: the symbol
 * @func: the function associated
 */
struct convert
{
	char *sym;
	int (*func)(va_list);
};
typedef struct convert conver_t;

int _printf(const char *format, ...);
int _putchar(char);
int print_char(va_list);
int print_str(va_list);
int print_percent(va_list);
int parser(const char *format, conver_t func_list[], va_list arg_list);
int print_int(va_list list);
int print_num(va_list arg_list);
#endif
