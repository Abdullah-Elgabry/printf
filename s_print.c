#include "main.h"

/**
 * prt_range - this func will prints the st & end
 * @_begin: the beginning loc
 * @_end: the ending loc
 * @except: exception not take
 *
 * Return: will return num of bytes 
 * 
 */


int prt_range(char *_begin, char *_end, char *except)
{
	int entir = 0;

	while (_begin <= _end)
	{
		if (_begin != except)
			entir += _putchar(*_begin);
		_begin++;
	}
	return (entir);
}

/**
 * _rev_fun - this func will rev the srt
 * 
 * @_ls: str
 * 
 * @params: struct
 *
 * Return: bytes
 */


int _rev_fun(va_list _ls, params_t *params)
{
	int len, entir = 0;
	char *str = va_arg(_ls, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			entir += _putchar(*str);
	}
	return (entir);
}


/**
 * _13_row - this func will prints str in 13
 * 
 * @_ls: str
 * 
 * @params: struct
 *
 * Return: bytes will be printed
 */


int _13_row(va_list _ls, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(_ls, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}


