include "main.h"

/**
 * _hex_lower - prints unsigned hex numbers in lowercase
 * @args: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _hex_lower(va_list args, values_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGN | CONVERT_LOWERC, params);
	if (params->flag_hash && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsignd = 1;
	return (c += _number(str, params));
}

/**
 * _hex_UPPER - prints unsigned hex numbers in uppercase
 * @args: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _hex_UPPER(va_list args, values_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGN, params);
	if (params->flag_hash && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsignd = 1;
	return (c += _number(str, params));
}
/**
 * _binary - prints unsigned binary number
 * @args: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _binary(va_list args, values_t *params)
{
	unsigned int n = va_arg(args, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGN, params);
	int c = 0;

	if (params->flag_hash && n)
		*--str = '0';
	params->unsignd = 1;
	return (c += _number(str, params));
}

/**
 * _octal - prints unsigned octal numbers
 * @args: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _octal(va_list args, values_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGN, params);

	if (params->flag_hash && l)
		*--str = '0';
	params->unsignd = 1;
	return (c += _number(str, params));
}
