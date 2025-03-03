#include "main.h"

/**
 * helper_sqrt - Helper function to find the square root.
 * @n: The number whose square root is to be found.
 * @guess: The current guess for the square root.
 *
 * Return: The natural square root of n, or -1 if not found.
 */
int helper_sqrt(int n, int guess)
{
	if (guess * guess == n) /* If guess squared equals n, return guess */
		return (guess);

	if (guess * guess > n) /* If guess squared exceeds n, no natural sqrt */
		return (-1);

	return (helper_sqrt(n, guess + 1)); /* Try the next number */
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number whose square root is to be found.
 *
 * Return: The natural square root of n, or -1 if n does not have one.
 */
int _sqrt_recursion(int n)
{
	if (n < 0) /* Negative numbers do not have natural square roots */
		return (-1);

	return (helper_sqrt(n, 0)); /* Start recursion with guess = 0 */
}

