#include "main.h"
/**
 * print_most_numbers - Prints numbers from 0 to 9 except 2 and 4.
 */
void print_most_numbers(void)
{
	char num[] = "01356789\n";
	int i = 0;

	while (num[i] != '\0')
	{
		_putchar(num[i]);
		i++;
	}
}

