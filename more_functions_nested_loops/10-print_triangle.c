#include "main.h"

/**
 * print_triangle - Prints a right-aligned triangle using the '#' character.
 * @size: The size of the triangle.
 */
void print_triangle(int size)
{
	int i, j, spaces;

	if (size > 0)
	{
		for (i = 1; i <= size; i++)
		{
			for (spaces = size - i; spaces > 0; spaces--)
			{
				_putchar(' '); /* Print leading spaces */
			}
			for (j = 0; j < i; j++)
			{
				_putchar('#'); /* Print '#' for the triangle */
			}
			_putchar('\n'); /* Move to the next line */
		}
	}
	else
	{
		_putchar('\n'); /* Print a newline if size is 0 or less */
	}
}

