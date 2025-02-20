#include "main.h"

/**
 * main - Tests the _islower function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'g';

	if (_islower(ch))
		_putchar('1');
	else
		_putchar('0');

	_putchar('\n');
	return (0);
}

