#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers from command-line arguments.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 if successful, 1 if incorrect number of arguments.
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3) /* Check if exactly two arguments are provided */
	{
		printf("Error\n");
		return (1);
	}

	/* Convert arguments from strings to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;

	printf("%d\n", result); /* Print the multiplication result */
	return (0);
}

