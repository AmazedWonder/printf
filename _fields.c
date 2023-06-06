#include "main.h"

/**
 * get_precision - funt to get precision from format string
 * @pre: format string
 * @params: the parameters struct
 * @args: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *pre, values_t *params, va_list args)
{
	int d = 0;

	if (*pre != '.')
		return (pre);
	pre++;
	if (*pre == '*')
	{
		d = va_arg(args, int);
		pre++;
	}
	else
	{
		while (_isdigit(*pre))
			d = d * 10 + (*pre++ - '0');
	}

	params->precision = d;
	return (pre);
}
