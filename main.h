#ifndef _MAIN_H_
#define _MAIN_H_
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

#include<stdarg.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

/**
*struct convert - defines a structure for functions and symbols
*
*@sym: The symbol
*@func: The function associated
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
int parser(const char *format, conver_t func_list[], va_list arg_list,
	int flags);
int print_String(va_list list);
int print_hexa_char(char c);
char *convert(unsigned long int num, int base, int uppercase);
int print_pointer(va_list list);
int print_int(va_list list);
int print_num(va_list arg_list);
int unsigned_int(va_list list);
int print_unsigned_num(unsigned int n);
int binary(va_list list);
void write_base(char *str);
unsigned int base_len(unsigned int num, int base);
char *_memcpy(char *dest, char *src, unsigned int n);
char *rev_string(char *s);
int check_hex(int num, char x);
int HEXA(va_list list);
int hexa(va_list list);
int octal(va_list list);
void print_buffer(char buffer[], int *buff_ind);
int _puts(char *str);
int print_reverse(va_list list);
int print_rot13(va_list list);
int get_flags(const char *format, int *i);


#endif
