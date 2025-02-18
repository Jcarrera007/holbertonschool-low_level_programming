#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the uppercase alphabet using only putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	for (ch = 'A'; ch <= 'Z'; ch++)
		putchar(ch);

	putchar('\n'); /* Print newline */

	return (0);
}

