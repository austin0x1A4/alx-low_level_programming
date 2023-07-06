#include "main.h"

/**
 * print_binary - Prints the binary equivalent of a decimal number.
 * @n: Number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;  /* Shift right to get the current bit */

		if (current & 1)  /* Check if the current bit is 1 */
		{
			_putchar('1');  /* Print '1' for a set bit */
			count++;
		}
		else if (count)
			_putchar('0');  /* Print '0' for unset bits after the first set bit */
	}

	if (!count)
		_putchar('0');  /* If the number is zero, print '0' */
}

