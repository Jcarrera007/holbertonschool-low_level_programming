#include "main.h"

/**
 * puts_half - Prints the second half of a string.
 * @str: Pointer to the string.
 */
void puts_half(char *str)
{
	int length = 0, start;

	while (str[length] != '\0') /* Find the length of the string */
		length++;

	if (length % 2 == 0)
		start = length / 2; /* If even, start from middle */
	else
		start = (length - 1) / 2 + 1; /* If odd, start from (length - 1) / 2 + 1 */

	while (str[start] != '\0') /* Print from start to end */
	{
		_putchar(str[start]);
		start++;
	}

	_putchar('\n'); /* Print a newline */
}

