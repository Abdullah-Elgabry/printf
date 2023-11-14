#include "main.h"

/**
 * ret_precn - this fun return the prec str
 *
 * @_ch_f: str
 *
 * @params: the param struct
 *
 * @_ls: the argument pointer
 *
 * Return: this will return a new ptr
 */

char *ret_precn(char *_ch_f, params_t *params, va_list _ls)
{
	int d = 0;

	if (*_ch_f != '.')
		return (_ch_f);
	_ch_f++;
	if (*_ch_f == '*')
	{
		d = va_arg(_ls, int);
		_ch_f++;
	}
	else
	{
		while (_check_dig(*_ch_f))
			d = d * 10 + (*_ch_f++ - '0');
	}
	params->precision = d;
	return (_ch_f);
}
