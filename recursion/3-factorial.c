#include "main.h"

/**
 * factorial - Returns the factorial of a given number.
 * @n: The number to calculate the factorial for.
 *
 * Return: Factorial of n, or -1 if n is negative.
 */

int factorial(int n)
{
	if (n < 0) /* Error case: Factorial is undefined for negative numbers */
		return (-1);

	if (n == 0) /* Base case: Factorial of 0 is 1 */
		return (1);

	return (n * factorial(n - 1)); /* Recursive call */
}

