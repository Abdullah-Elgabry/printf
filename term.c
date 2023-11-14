#include "main.h"

/**
 * check_spec - this a searcher fun
 * @s: string
 *
 *
 * Return: bytes
 */

int (*check_spec(char *s))(va_list _ls, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", prt_ch},
		{"d", prt_int},
		{"i", prt_int},
		{"s", prt_str},
		{"%", print_percent},
		{"b", bin_print},
		{"o", _oct_prt},
		{"u", unsign_int},
		{"x", _Hexa_Dec},
		{"X", _hex_prt},
		{"_ch_f", _location},
		{"S", print_S},
		{"r", _rev_fun},
		{"R", _13_row},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specf)
	{
		if (*s == specifiers[i].specf[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * ret_form - this fun check the format
 *
 * @s: string format
 *
 * @_ls: ptr
 *
 * @params: struct
 *
 * Return: bytes
 */

int ret_form(char *s, va_list _ls, params_t *params)
{
	int (*f)(va_list, params_t *) = check_spec(s);

	if (f)
		return (f(_ls, params));
	return (0);
}

/**
 * ret_fl - this is fun checks for flag fun
 *
 * @s: str
 *
 * @params: struct
 *
 * Return: flag
 */

int ret_fl(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->flag_hash = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * ret_mod - this fun will ret func
 *
 * @s: str
 *
 * @params: struct
 *
 * Return: mod
 */


int ret_mod(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->_filter = 1;
		break;
	case 'l':
		i = params->p_fill = 1;
		break;
	}
	return (i);
}

/**
 * ret_wid - this fun will ret width
 *
 * @s: str
 *
 * @params: struct
 *
 * @_ls: ptr
 *
 * Return: the n generated ptr
 */

char *ret_wid(char *s, params_t *params, va_list _ls)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(_ls, int);
		s++;
	}
	else
	{
		while (_check_dig(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}

