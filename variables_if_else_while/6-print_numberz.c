#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints single-digit numbers of base 10 using only putchar twice.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num = 0;

	while (num < 10)
		putchar(num++ + '0'); /* Convert integer to character */

	putchar('\n'); /* Print newline */

	return (0);
}

