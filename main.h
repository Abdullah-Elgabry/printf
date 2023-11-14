#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUF_S 1024
#define BUF_RS -1


#define NULL_STRING "(null)"

#define _pr_st {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct param - param struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if flag_hash specified
 * @flag_hash: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @_filter: on if _filter is specified
 * @p_fill: on if p_fill is specified
 *
 */
typedef struct param
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int flag_hash		: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int _filter		: 1;
	unsigned int p_fill		: 1;
} params_t;

/**
 * struct specf - Struct token
 *
 * @specf: format token
 *
 * @f: The function associated
 */
typedef struct specf
{
	char *specf;
	int (*f)(va_list, params_t *);
} specifier_t;

int put_ch(char *str);
int _putchar(int c);

int prt_ch(va_list _ls, params_t *params);
int prt_int(va_list _ls, params_t *params);
int prt_str(va_list _ls, params_t *params);
int print_percent(va_list _ls, params_t *params);
int print_S(va_list _ls, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int unsign_int(va_list _ls, params_t *params);
int _location(va_list _ls, params_t *params);

int (*check_spec(char *s))(va_list _ls, params_t *params);
int ret_form(char *s, va_list _ls, params_t *params);
int ret_fl(char *s, params_t *params);
int ret_mod(char *s, params_t *params);
char *ret_wid(char *s, params_t *params, va_list _ls);

int _Hexa_Dec(va_list _ls, params_t *params);
int _hex_prt(va_list _ls, params_t *params);
int bin_print(va_list _ls, params_t *params);
int _oct_prt(va_list _ls, params_t *params);

int prt_range(char *_begin, char *_end, char *except);
int _rev_fun(va_list _ls, params_t *params);
int _13_row(va_list _ls, params_t *params);

int _check_dig(int c);
int _ch_length(char *s);
int print_number(char *str, params_t *params);
int prt_r_sh(char *str, params_t *params);
int prt_l_s(char *str, params_t *params);

void _reset_buf(params_t *params, va_list _ls);

char *ret_precn(char *_ch_f, params_t *params, va_list _ls);

int _printf(const char *format, ...);

#endif
