include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}


/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int _number(char *str, values_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsignd && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->flag_minus)
		return (_numberAlign_right(str, params));
	else
		return (_numberAlign_left(str, params));
}

/**
 * _numberAlign_right - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int _numberAlign_right(char *str, values_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->flag_zero && !params->flag_minus)
		pad_char = '0';
	neg = neg2 = (!params->unsignd && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->flag_minus)
		str++;
	else
		neg = 0;
	if ((params->flag_plus && !neg2) ||
		(!params->flag_plus && params->flag_space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->flag_plus && !neg2 && pad_char == '0' && !params->unsignd)
		n += _putchar('+');
	else if (!params->flag_plus && params->flag_space && !neg2 &&
		!params->unsignd && params->flag_zero)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->flag_plus && !neg2 && pad_char == ' ' && !params->unsignd)
		n += _putchar('+');
	else if (!params->flag_plus && params->flag_space && !neg2 &&
		!params->unsignd && !params->flag_zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}


/**
 * _numberAlign_left - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int _numberAlign_left(char *str, values_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->flag_zero && !params->flag_minus)
		pad_char = '0';
	neg = neg2 = (!params->unsignd && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->flag_minus)
		str++;
	else
		neg = 0;

	if (params->flag_plus && !neg2 && !params->unsignd)
		n += _putchar('+'), i++;
	else if (params->flag_space && !neg2 && !params->unsignd)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
