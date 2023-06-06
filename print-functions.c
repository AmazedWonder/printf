#include "main.h"

/**
 * print_char - prints character
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int _char(va_list args, values_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(args, int);

	if (params->flag_minus)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->flag_minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * _int - prints integer
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int _int(va_list args, values_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(args, long);
	else if (params->h_modifier)
		l = (short int)va_arg(args, int);
	else
		l = (int)va_arg(args, int);
	return (_number(convert(l, 10, 0, params), params));
}

/**
 * _string - prints string
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int _string(va_list args, values_t *params)
{
	char *str = va_arg(args, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = Empty_String;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->flag_minus)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->flag_minus)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * _percent - prints string
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int _percent(va_list args, values_t *params)
{
	(void)args;
	(void)params;
	return (_putchar('%'));
}

/**
 * _S - custom format specifier
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int _S(va_list args, values_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(Empty_String));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

