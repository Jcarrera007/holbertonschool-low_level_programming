#include "main.h"

/**
 * print_numbers - Prints numbers from 0 to 9, followed by a new line.
 */
void print_numbers(void)
{
	char num[] = "0123456789";
	int i = 0;

	while (num[i] != '\0')
	{
		_putchar(num[i]);
		i++;
	}
	_putchar('\n');
}

