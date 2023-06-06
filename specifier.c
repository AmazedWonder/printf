include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 * @args: argument
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list args, values_t *params)
{
	specifier_t specifiers[] = {
		{"c", _char},
		{"d", _int},
		{"i", _int},
		{"s", _string},
		{"%", _percent},
		{"b", _binary},
		{"o", _octal},
		{"u", _unsigned},
		{"x", _hex_lower},
		{"X", _hex_UPPER},
		{"p", _address},
		{"S", _S},
		{"r", _reverse},
		{"R", _rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_function - gets format function
 * @s:  string formatted
 * @args: argument
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_function(char *s, va_list args, values_t *params)
{
	int (*f)(va_list, values_t *) = get_specifier(s);

	if (f)
		return (f(args, params));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, values_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->flag_plus = 1;
			break;
		case ' ':
			i = params->flag_space = 1;
			break;
		case '#':
			i = params->flag_hash = 1;
			break;
		case '-':
			i = params->flag_minus = 1;
			break;
		case '0':
			i = params->flag_zero = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, values_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @args: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, values_t *params, va_list args)
/* should this function use char **s and modify the pointer? */
{
	int digit = 0;

	if (*s == '*')
	{
		digit = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			digit = digit * 10 + (*s++ - '0');
	}
	params->width = digit;
	return (s);
}


