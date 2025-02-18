#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the lowercase and uppercase alphabet using only putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z') /* Print lowercase letters */
		putchar(ch++);

	ch = 'A';
	while (ch <= 'Z') /* Print uppercase letters */
		putchar(ch++);

	putchar('\n'); /* Print newline */

	return (0);
}

