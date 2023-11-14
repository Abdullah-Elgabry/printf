#include "main.h"

/**
 * prt_ch - this fun will print charcater
 *
 * @_ls: arg
 *
 * @params: struct
 *
 * Return: char
 */

int prt_ch(va_list _ls, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, entir = 0, ch = va_arg(_ls, int);

	if (params->minus_flag)
		entir += _putchar(ch);
	while (pad++ < params->width)
		entir += _putchar(pad_char);
	if (!params->minus_flag)
		entir += _putchar(ch);
	return (entir);
}

/**
 * prt_int - this fun will prints int
 *
 * @_ls: ptr
 * @params: struct
 *
 * Return: char will printed
 */


int prt_int(va_list _ls, params_t *params)
{
	long l;

	if (params->p_fill)
		l = va_arg(_ls, long);
	else if (params->_filter)
		l = (short int)va_arg(_ls, int);
	else
		l = (int)va_arg(_ls, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * prt_str - prints string
 *
 * @_ls: argument pointer
 *
 * @params: the param struct
 *
 * Return: number chars printed
 */
int prt_str(va_list _ls, params_t *params)
{
	char *str = va_arg(_ls, char *), pad_char = ' ';
	unsigned int pad = 0, entir = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _ch_length(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				entir += _putchar(*str++);
		else
			entir += put_ch(str);
	}
	while (j++ < params->width)
		entir += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				entir += _putchar(*str++);
		else
			entir += put_ch(str);
	}
	return (entir);
}

/**
 * print_percent - this fun will prints str
 *
 * @_ls: ptr
 *
 * @params: struct
 *
 * Return: char
 */


int print_percent(va_list _ls, params_t *params)
{
	(void)_ls;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specf
 *
 * @_ls: argument pointer
 *
 * @params: the param struct
 *
 * Return: number chars printed
 */
int print_S(va_list _ls, params_t *params)
{
	char *str = va_arg(_ls, char *);
	char *hex;
	int entir = 0;

	if ((int)(!str))
		return (put_ch(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			entir += _putchar('\\');
			entir += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				entir += _putchar('0');
			entir += put_ch(hex);
		}
		else
		{
			entir += _putchar(*str);
		}
	}
	return (entir);
}

