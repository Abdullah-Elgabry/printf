#include "main.h"

/**
 * _Hexa_Dec - this fun will print hexa_dec num in lc
 * @_ls: the argument pointer
 * @params: this is a stuct
 *
 * Return: int (size)
 */



int _Hexa_Dec(va_list _ls, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->p_fill)
		l = (unsigned long)va_arg(_ls, unsigned long);
	else if (params->_filter)
		l = (unsigned short int)va_arg(_ls, unsigned int);
	else
		l = (unsigned int)va_arg(_ls, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->flag_hash && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * _hex_prt - this fun will print hexa_dec num in UC
 * @_ls: ptr
 * @params: struct for args
 *
 * Return: int (size of byts)
 */


int _hex_prt(va_list _ls, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->p_fill)
		l = (unsigned long)va_arg(_ls, unsigned long);
	else if (params->_filter)
		l = (unsigned short int)va_arg(_ls, unsigned int);
	else
		l = (unsigned int)va_arg(_ls, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->flag_hash && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}



/**
 * bin_print - this fun will prints bin number
 * @_ls: ptr for arg
 * @params: this is struct
 *
 * Return: int (size)
 */


int bin_print(va_list _ls, params_t *params)
{
	unsigned int n = va_arg(_ls, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->flag_hash && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * _oct_prt - this fun will prints octal numbers
 * @_ls: ptr for arg
 *
 * @params: this is struct
 *
 * Return: int size
 *
 */


int _oct_prt(va_list _ls, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->p_fill)
		l = (unsigned long)va_arg(_ls, unsigned long);
	else if (params->_filter)
		l = (unsigned short int)va_arg(_ls, unsigned int);
	else
		l = (unsigned int)va_arg(_ls, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->flag_hash && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

