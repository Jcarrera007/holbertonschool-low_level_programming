#include "main.h"

/**
 * main - Print var
 *
 * Return: Always 0
 */
int main(void)
{
	char *p = "_putchar";

	while (*p)
	{
		_putchar(*p);
		p++;
	}

	_putchar('\n');
	return (0);
}
