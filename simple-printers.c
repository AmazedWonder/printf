#include "main.h"

/**
 * _from - prints a range of character address
 * @begin: beginning of address
 * @end: end of an address
 * @exclude: excluded address
 *
 * Return: number bytes printed
 */
int _from(char *begin, char *end, char *exclude)
{
	int add = 0;

	while (begin <= end)
	{
		if (begin != exclude)
			add += _putchar(*begin);
		begin++;
	}
	return (add);
}

/**
 * _reverse - prints string in reverse
 * @args: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int _reverse(va_list args, values_t *params)
{
	int length, sum = 0;
	char *str = va_arg(args, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * _rot13 - prints string in rot13
 * @args: string to be used
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int _rot13(va_list args, values_t *params)
{
	int i, ind;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(args, char *);
	(void)params;

	i = 0;
	ind = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			ind = a[i] - 65;
			count += _putchar(arr[ind]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
