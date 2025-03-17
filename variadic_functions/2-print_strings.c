#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - Prints strings followed by a new line
 * @separator: String to be printed between strings
 * @n: Number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);  /* Initialize the argument list */

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);  /* Retrieve the string argument */

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		/* Print separator only if it's not NULL and not the last element */
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	va_end(args);  /* Clean up the argument list */

	printf("\n");  /* Print new line at the end */
}

