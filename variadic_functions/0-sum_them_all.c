#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all its parameters
 * @n: Number of arguments
 * Return: Sum of all arguments, or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(args, n);  /* Initialize the argument list */

	for (i = 0; i < n; i++)
		sum += va_arg(args, int);  /* Retrieve each argument and add to sum */

	va_end(args);  /* Clean up the argument list */

	return (sum);
}

