clude <unistd.h>

/**
* _putchar - Writes a character to stdout
* @c: The character to write
* Return: Number of characters written
*/
int _putchar(char c)
{
return write(1, &c, 1);
}

