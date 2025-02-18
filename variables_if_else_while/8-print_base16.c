#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints numbers of base 16 in lowercase using only putchar three times.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num = 0;

	while (num < 10)
		putchar(num++ + '0'); /* Print digits 0-9 */

	num = 'a';
	while (num <= 'f')
		putchar(num++); /* Print letters a-f */

	putchar('\n'); /* Print newline */

	return (0);
}

