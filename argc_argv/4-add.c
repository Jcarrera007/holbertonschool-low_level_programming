#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - Checks if a string contains only digits.
 * @str: The string to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *str)
{
	int i = 0;

	if (str[i] == '\0') /* Empty string is not a number */
		return (0);

	while (str[i]) /* Check each character */
	{
		if (!isdigit(str[i])) /* If not a digit, return 0 */
			return (0);
		i++;
	}

	return (1);
}

/**
 * main - Adds positive numbers from command-line arguments.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, 1 if an invalid argument is found.
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1) /* No numbers provided */
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++) /* Iterate through arguments */
	{
		if (!is_number(argv[i])) /* Check if argument is a valid number */
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]); /* Convert to integer and add */
	}

	printf("%d\n", sum); /* Print the sum */
	return (0);
}

