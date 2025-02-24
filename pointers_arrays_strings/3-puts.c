#include "main.h"

/**
 * _puts - Prints a string followed by a new line to stdout.
 * @str: Pointer to the string to print.
 */
void _puts(char *str)
{
	while (*str != '\0') /* Loop until the null terminator */
	{
		_putchar(*str); /* Print the current character */
		str++; /* Move to the next character */
	}
	_putchar('\n'); /* Print a newline at the end */
}

