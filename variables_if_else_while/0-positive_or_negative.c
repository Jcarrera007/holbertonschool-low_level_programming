#include <stdlib.h>
#include <time.h>
#include <stdio.h> /* Include stdio.h for printf */

/**
 * main - Entry point working with variable if, else
  * Return: Always 0 (Success)
  * using a source code
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* Check if n is positive, negative, or zero */
	if (n > 0)
		printf("%d is positive\n", n);/*%d= interger; ,n outside the ) = the int n*/
	else if (n == 0)
		printf("%d is zero\n", n);
	else
		printf("%d is negative\n", n);

	return (0);
}

