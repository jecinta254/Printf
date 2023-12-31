#include "main.h"

/**
 * _printf - Jecinta and karamagueye Printf function
 * get_size - calculating the size to cast the argumentus
 * @format: Formatted string where it print the arguments
 * @i: List of arguments to be printed input
 * Return: Return Precision
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
