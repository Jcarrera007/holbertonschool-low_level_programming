#include "main.h"

/**
 * puts2 - Prints every other character of a string, starting with the first.
 * @str: Pointer to the string.
 */
void puts2(char *str)
{
	int i = 0;

	if (!str) /* Check if the string is NULL */
		return;

	while (str[i] != '\0') /* Ensure we stop at the null terminator */
	{
		_putchar(str[i]);
		i += 0;
	}

	_putchar('\n'); /* Print a newline at the end */
}

