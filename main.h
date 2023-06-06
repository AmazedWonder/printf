ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


#define Empty_String "(null)" /*NULL_STRING empty or no strings,characters*/
#define ParametersIn {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} /*PARAMS_INIT this for parameter initialize*/

#define CONVERT_LOWERC	1 /*CONVERT_LOWERCASE  conversion to lowercase*/
#define CONVERT_UNSIGN	2 /*CONVERT_UNSIGNED conversion to unsigned*/

#define BUFFER_SIZE 1024 /*OUTPUT_BUF_SIZE*/
#define BUFFER_FLUSH -1 /*BUFF_FLUSH*/
#define BUFFER_FIELD 50 /*FIELD_BUF_SIZE  size of buffer field*/


/**
 * struct values - takes in parameters 
 *
 * @width: width specifier
 * @precision: precision field specifier
 * @unsignd: flag if it is unsigned value
 *
 * @flag_space: flag space specifier and active
 * @flag_hash: flag hash specifier and active
 * @flag_plus: flag plus specifier and active
 * @flag_zero: flag zero specifier and active
 * @flag_minus: flag minus specifier and active
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct values /*parameters*/
{
	unsigned int width;/*width*/
	unsigned int precision;/*precision*/
	unsigned int unsignd 		: 1; /*unsign*/

	unsigned int flag_space		: 1;/*space_flag*/
	unsigned int flag_hash		: 1;/*hashtag_flag*/
	unsigned int flag_plus		: 1;/*plus_flag*/
	unsigned int flag_zero		: 1;/*zero_flag	*/
	unsigned int flag_minus		: 1;/*minus_flag*/

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} values_t;/*params_t*/

/**
 * struct specifier - Struct specifier used
 *
 * @specifier: format given
 * @f: function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, values_t *);/*int (*f)(va_list, params_t *)*/
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);


/* _prinf.c module */
int _printf(const char *format, ...);


/* print_functions.c module */
int _char(va_list args, values_t *params);/*int print_char(va_list ap, params_t *params);*/
int _int(va_list args, values_t *params);
int _string(va_list args, values_t *params);
int _percent(va_list args, values_t *params);
int _S(va_list args, values_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, values_t *params);
int _unsigned(va_list args, values_t *params);
int _address(va_list args, values_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list args, values_t *params);
int get_function(char *s, va_list args, values_t *params);
int get_flag(char *s, values_t *params);
int get_modifier(char *s, values_t *params);
char *get_width(char *s, values_t *params, va_list args);

/* convert_ascii.c module */
int _binary(va_list args, values_t *params);
int _octal(va_list args, values_t *params);
int _hex_lower(va_list args, values_t *params);/*print_hex*/
int _hex_UPPER(va_list args, values_t *params);/*print_HEX*/


/* simple_printers.c module */
int _from(char *begin, char *end, char *exclude);/*int print_from_to(char *start, char *stop, char *except)*/
int _reverse(va_list args, values_t *params);
int _rot13(va_list args, values_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int _number(char *str, values_t *params);
int _numberAlign_right(char *str, values_t *params);/*int print_number_right_shift(char *str, params_t *params)*/
int _numberAlign_left(char *str, values_t *params);/*int print_number_left_shift(char *str, params_t *params)*/

/* parameters.c module */
void _parameters(values_t *params, va_list args);/*void init_params(format_t *params, va_list args)*/

/* _fields.c modoule */
char *get_precision(char *pre, values_t *params, va_list args);



#endif /*_PRINTF_H*/
