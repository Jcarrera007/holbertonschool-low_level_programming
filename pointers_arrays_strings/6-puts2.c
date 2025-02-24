#include "main.h"

/**
 * puts2 - Prints every other character of a string.
 * @str: Pointer to the string.
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0') /* Iterate through the string */
	{
		_putchar(str[i]); /* Print the current character */
		i += 2; /* Move to the next alternate character */
	}

	_putchar('\n'); /* Print a newline at the end */
}

