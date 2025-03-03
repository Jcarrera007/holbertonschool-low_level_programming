#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to print in reverse.
 *
 * Return: void.
 */

void _print_rev_recursion(char *s)
{
	if (*s == '\0') /* Base case: End of string */
		return;

	_print_rev_recursion(s + 1); /* Recursive call to move forward */
	_putchar(*s); /* Print character after returning from recursion */
}

