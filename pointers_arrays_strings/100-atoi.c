#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: Pointer to the string.
 *
 * Return: The integer value of the string.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int started = 0; /* Flag to check if a number has started */

	while (*s) /* Iterate through the string */
	{
		if (*s == '-') /* Flip sign for each '-' encountered */
			sign *= -1;
		else if (*s == '+') /* Ignore '+' signs */
			sign *= 1;
		else if (*s >= '0' && *s <= '9') /* If it's a digit, process it */
		{
			started = 1; /* Mark that we started processing numbers */
			result = result * 10 + (*s - '0'); /* Build the integer */
		}
		else if (started) /* Stop processing after numbers end */
			break;

		s++; /* Move to the next character */
	}

	return (result * sign);
}

