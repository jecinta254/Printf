#include "main.h"

/**
 * _printf - Jecinta and karamagueye Printf function
 * get_width - calculating the width to print
 * @format: Formatted string where it prints the arguments.
 * @i: List of arguments to be printed input.
 * @list: list of arguments as input.
 * Return: Return the width
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
