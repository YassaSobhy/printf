#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 *
 * @format: format.
 *
 * Return: return the Printed chars.
 */

int _printf(const char *format, ...)
{
	int k, p = 0, p_ch = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[k], 1);*/
			p_ch++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &k);
			width = get_width(format, &k, list);
			precision = get_precision(format, &k, list);
			size = get_size(format, &k);
			++k;
			p = handle_print(format, &k, list, buffer,
				flags, width, precision, size);
			if (p == -1)
				return (-1);
			p_ch += p;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (p_ch);
}

/**
 * print_buffer - if exit print content of buffer
 *
 * @buffer: Array of chars
 *
 * @buff_ind: The index where next character
 *
 * should be inserted corresponds to its length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
