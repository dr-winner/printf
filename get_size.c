#include "main.h"

/**
 * get_size - this calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int deSize = 0;

	if (format[curr_i] == 'l')
		deSize = S_LONG;
	else if (format[curr_i] == 'h')
		deSize = S_SHORT;

	if (deSize == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (deSize);
}
