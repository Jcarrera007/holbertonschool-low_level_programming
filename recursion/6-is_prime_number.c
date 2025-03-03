#include "main.h"

/**
 * helper_prime - Helper function to check if n is prime.
 * @n: The number to check.
 * @divisor: The current divisor being tested.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int helper_prime(int n, int divisor)
{
	if (divisor * divisor > n) /* If no divisors found, n is prime */
		return (1);

	if (n % divisor == 0) /* If n is divisible by divisor, not prime */
		return (0);

	return (helper_prime(n, divisor + 1)); /* Check next divisor */
}

/**
 * is_prime_number - Checks if a number is a prime number.
 * @n: The number to check.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2) /* 0 and 1 are not prime numbers */
		return (0);

	return (helper_prime(n, 2)); /* Start checking from divisor = 2 */
}

