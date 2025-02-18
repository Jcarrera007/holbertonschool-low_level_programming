#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints numbers of base 16 in lowercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num = 0;

	while (num < 10)
		putchar(num++ + '0');

	num = 'a';
	while (num <= 'f')
		putchar(num++);

	putchar('\n');

	return (0);
}

