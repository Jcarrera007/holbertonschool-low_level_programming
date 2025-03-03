#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the minimum number of coins to make change.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, 1 if incorrect arguments.
 */

int main(int argc, char *argv[])
{
	int cents, coins = 0;
	int denominations[] = {25, 10, 5, 2, 1}; /* Coin values */
	int i;

	if (argc != 2) /* Check if exactly one argument is provided */
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]); /* Convert input to integer */

	if (cents < 0) /* If negative, print 0 */
	{
		printf("0\n");
		return (0);
	}

	/* Calculate the minimum number of coins */
	for (i = 0; i < 5; i++)
	{
		while (cents >= denominations[i])
		{
			cents -= denominations[i];
			coins++;
		}
	}

	printf("%d\n", coins); /* Print result */
	return (0);
}

