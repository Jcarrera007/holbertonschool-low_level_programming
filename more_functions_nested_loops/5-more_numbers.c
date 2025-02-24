#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers from 0 to 14,
 * followed by a new line.
 */
void more_numbers(void)
{
	int i, j;
	char numbers[] = "01234567891011121314\n";

	for (i = 0; i < 10; i++)
	{
		j = 0;
		while (numbers[j] != '\0')
		{
			_putchar(numbers[j]);
			j++;
		}
	}
}

