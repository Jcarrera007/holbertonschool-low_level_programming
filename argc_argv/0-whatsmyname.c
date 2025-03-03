#include <stdio.h>

/**
 * main - Prints the program name followed by a new line.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments (argv[0] contains program name).
 *
 * Return: Always 0 (Success).
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]); /* Print the program name */
	return (0);
}
