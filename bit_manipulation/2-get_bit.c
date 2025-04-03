#include "main.h"

/**
 * get_bit - return the value of a bit at a given index
 * @n: the number to extract the bit from
 * @index: the position of the bit (starting from 0)
 *
 * Return: the value of the bit (0 or 1), or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(n) * 8))
		return (-1);
	return ((n >> index) & 1);
}

