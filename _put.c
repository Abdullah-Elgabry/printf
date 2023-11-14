#include "main.h"


/**
 * put_ch - this func will print a str + /n
 * @str: str will be printed
 * Return: it's a void func
 */

int put_ch(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - this func will types char c
 *
 * @c: this the char will be printed
 *
 * Return: 1 or -1
 */


int _putchar(int c)
{
	static int i;
	static char buf[BUF_S];

	if (c == BUF_RS || i >= BUF_S)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_RS)
		buf[i++] = c;
	return (1);
}
