#include <stdlib.h>
#include <time.h>
#include <stdio.h> /* Include stdio.h for printf */

/**
 * main - Entry point of the program
 *
 * Description: Determines the last digit of a random number and
 * prints whether it is greater than 5, 0, or less than 6 and not 0.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, last_digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_digit = n % 10; /* Get the last digit */

	/* Print the required output */
	printf("Last digit of %d is %d ", n, last_digit);
	if (last_digit > 5)
		printf("and is greater than 5\n");
	else if (last_digit == 0)
		printf("and is 0\n");
	else
		printf("and is less than 6 and not 0\n");

	return (0);
}

