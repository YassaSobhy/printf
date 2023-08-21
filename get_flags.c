#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: A string with appropriate
 * formatting to display the arguments.
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int f, c_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		for (f = 0; FLAGS_CH[f] != '\0'; f++)
			if (format[c_i] == FLAGS_CH[f])
			{
				flags |= FLAGS_ARR[f];
				break;
			}

		if (FLAGS_CH[f] == 0)
			break;
	}

	*i = c_i - 1;

	return (flags);
}
