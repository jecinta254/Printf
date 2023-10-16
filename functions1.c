#include "main.h"

/**
 * _printf - Jecinta and karamagueye Printf function
 * print_unsigned - Printing an unsigned number
 * @types: List a of arguments input
 * @buffer: Buffer array to handle print input
 * @flags:  Calculates active flags input
 * @width: get width as an input
 * @precision: Precision specification as an input
 * @size: Size specifier input
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/** 
 * _printf - Jecinta and karamagueye Printf function
 * print_octal - Printing an unsigned number in octal notation
 * @types: Lista of arguments input
 * @buffer: Buffer array to handle print input
 * @flags:  Calculates active flags input
 * @width: get width input
 * @precision: Precision specification input
 * @size: Size specifier input
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/** 
 * _printf - Jecinta and karamagueye Printf function
 * print_hexadecimal - Printing an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width input
 * @precision: Precision specification
 * @size: Size specifier input
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** 
 * _printf - Jecinta and karamagueye Printf function
 * print_hexa_upper - Printing an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments input
 * @buffer: Buffer array to handle print input
 * @flags:  Calculates active flags input
 * @width: get width input
 * @precision: Precision specification input
 * @size: Size specifier input
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/** 
 * _printf - Jecinta and karamagueye Printf function
 * print_hexa - Printing a hexadecimal number in lower or upper
 * @types: Lista of arguments input
 * @map_to: Array of values to map the number to input
 * @buffer: Buffer array to handle print input
 * @flags:  Calculates active flags input
 * @flag_ch: Calculates active flags input
 * @width: get width input
 * @precision: Precision specification input
 * @size: Size specifier input
 * @size: Size specification input
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

