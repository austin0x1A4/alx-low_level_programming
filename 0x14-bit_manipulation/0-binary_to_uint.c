#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: String containing the binary number.
 *
 * Return: The converted number, or 0 if there is an invalid character
 *         in the string or if the string is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')  /* Check for invalid characters */
			return (0);

		dec_val = 2 * dec_val + (b[i] - '0'); /* Convert binary to decimal */
	}

	return (dec_val);
}

