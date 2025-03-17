#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 * @argc: Argument count
 * @argv: Argument vector (number of bytes to print)
 *
 * Return: 0 on success, exits with status 1 or 2 on errors
 */
int main(int argc, char *argv[])
{
	int bytes, i;
	unsigned char *ptr;

	/* Validate argument count */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* Convert argument to integer */
	bytes = atoi(argv[1]);

	/* Validate byte count */
	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* Pointer to the main function */
	ptr = (unsigned char *)main;

	/* Print the opcodes */
	for (i = 0; i < bytes; i++)
	{
		printf("%02x", ptr[i]);
		if (i < bytes - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}

