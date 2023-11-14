#include "main.h"

/**
 * _reset_buf - clears struct fields and reset buf
 * @params: the param struct
 * @_ls: the argument pointer
 *
 * Return: void
 */
void _reset_buf(params_t *params, va_list _ls)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->flag_hash = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->_filter = 0;
	params->p_fill = 0;
	(void)_ls;
}
