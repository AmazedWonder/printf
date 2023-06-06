#include "main.h"

/**
 * _parameters - clears struct fields and reset buffer
 * @params: the parameters struct
 * @args: the argument pointer
 *
 * Return: void
 */
void _parameters(values_t *params, va_list args)
{
	params->unsignd = 0;

	params->flag_plus = 0;
	params->flag_space = 0;
	params->flag_hash = 0;
	params->flag_zero = 0;
	params->flag_minus = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)args;
}
