#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - this is a printf function
 * @format: this is the format
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int x, printed = 0, printed_characters = 0;
	int flags, width, prec, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[x], 1);*/
			printed_characters++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &x);
			width = get_width(format, &x, list);
			prec = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buffer,
				flags, width, prec, size);
			if (printed == -1)
				return (-1);
			printed_characters += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_characters);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
