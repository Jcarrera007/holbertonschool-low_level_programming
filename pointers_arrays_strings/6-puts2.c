#include "main.h"
#include <stddef.h>

/**
 * puts2 - Prints every other character of a string, starting with the first.
 * @str: Pointer to the string.
 */
void puts2(char *str)
{
	int i = 0;

	if (str == NULL) /* Safety check for NULL pointer */
		return;

	while (str[i] != '\0') /* Ensure stopping at the null terminator */
	{
		_putchar(str[i]); /* Print the current character */

		if (str[i + 1] == '\0') /* Prevent reading beyond the string */
			break;

		i += 2; /* Move to the next alternate character */
	}

	_putchar('\n'); /* Print a newline at the end */
}

