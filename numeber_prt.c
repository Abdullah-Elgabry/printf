#include "main.h"

/**
 * _check_dig - cthis checker fun
 *
 * @c: the chr will test
 *
 * Return: one or zero
 */

int _check_dig(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _ch_length - func will print leng of charcater
 *
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */

int _ch_length(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - this fun will print a number
 *
 * @str: this id the str as a base
 *
 * @params: struct
 *
 * Return: char
 */


int print_number(char *str, params_t *params)
{
	unsigned int i = _ch_length(str);
	int gen = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (gen)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (gen)
		*--str = '-';

	if (!params->minus_flag)
		return (prt_r_sh(str, params));
	else
		return (prt_l_s(str, params));
}

/**
 * prt_r_sh - this fun will print a number
 *
 * @str: this id the str as a base
 *
 * @params: struct
 *
 * Return: char
 */

int prt_r_sh(char *str, params_t *params)
{
	unsigned int n = 0, gen, gen2, i = _ch_length(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	gen = gen2 = (!params->unsign && *str == '-');
	if (gen && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		gen = 0;
	if ((params->plus_flag && !gen2) ||
		(!params->plus_flag && params->space_flag && !gen2))
		i++;
	if (gen && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !gen2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !gen2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (gen && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !gen2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !gen2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += put_ch(str);
	return (n);
}

/**
 * prt_l_s - this func will prints num
 *
 * @str: base num
 *
 * @params: struct
 *
 * Return: chars printed
 */

int prt_l_s(char *str, params_t *params)
{
	unsigned int n = 0, gen, gen2, i = _ch_length(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	gen = gen2 = (!params->unsign && *str == '-');
	if (gen && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		gen = 0;

	if (params->plus_flag && !gen2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !gen2 && !params->unsign)
		n += _putchar(' '), i++;
	n += put_ch(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
