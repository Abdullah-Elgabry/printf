#include "main.h"

/**
 * convert - this is a fun that will convrt
 *
 * @num: l num
 *
 * @base: this is the base
 *
 * @flags: arg
 *
 * @params: struct
 *
 * Return: str
 */


char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * unsign_int - this func will print unsign int
 * @_ls: ptr
 * @params: struc
 *
 * Return: this will return byts
 */
int unsign_int(va_list _ls, params_t *params)
{
	unsigned long l;

	if (params->p_fill)
		l = (unsigned long)va_arg(_ls, unsigned long);
	else if (params->_filter)
		l = (unsigned short int)va_arg(_ls, unsigned int);
	else
		l = (unsigned int)va_arg(_ls, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * _location - this func prints the loc
 * @_ls: (ptr)
 * @params: struc
 *
 * Return: this will return byts
 */
int _location(va_list _ls, params_t *params)
{
	unsigned long int n = va_arg(_ls, unsigned long int);
	char *str;

	if (!n)
		return (put_ch("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
