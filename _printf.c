#include "main.h"


/**
 * _printf - function that will print str, int, etc..
 * @format: this is the format of the string will passed to func
 * Return: integer
 */


int _printf(const char *format, ...)
{
	int entir = 0;
	va_list _ls;
	char *_ch_f, *_begin;
	params_t params = _pr_st;

	va_start(_ls, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (_ch_f = (char *)format; *_ch_f; _ch_f++)
	{
		_reset_buf(&params, _ls);
		if (*_ch_f != '%')
		{
			entir += _putchar(*_ch_f);
			continue;
		}
		_begin = _ch_f;
		_ch_f++;
		while (ret_fl(_ch_f, &params))
		{
			_ch_f++;
		}
		_ch_f = ret_wid(_ch_f, &params, _ls);
		_ch_f = ret_precn(_ch_f, &params, _ls);
		if (ret_mod(_ch_f, &params))
			_ch_f++;
		if (!check_spec(_ch_f))
			entir += prt_range(_begin, _ch_f,
				params.p_fill || params._filter ? _ch_f - 1 : 0);
		else
			entir += ret_form(_ch_f, _ls, &params);
	}
	_putchar(BUF_RS);
	va_end(_ls);
	return (entir);
}
