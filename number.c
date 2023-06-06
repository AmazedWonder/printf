include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, values_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGN) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERC ? "0123456789abcdef" : "0123456789ABCDEF";
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
 * _unsigned - prints unsigned integer numbers
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _unsigned(va_list args, values_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	params->unsignd = 1;
	return (_number(convert(l, 10, CONVERT_UNSIGN, params), params));
}



/**
 * _address - prints address
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _address(va_list args, values_t *params)
{
	unsigned long int n = va_arg(args, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGN | CONVERT_LOWERC, params);
	*--str = 'x';
	*--str = '0';
	return (_number(str, params));
}
