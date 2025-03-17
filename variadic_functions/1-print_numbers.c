#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Prints numbers followed by a new line
 * @separator: String to be printed between numbers
 * @n: Number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;

    va_start(args, n);  /* Initialize the argument list */

    for (i = 0; i < n; i++)
    {
        printf("%d", va_arg(args, int));

        /* Print separator only if it's not NULL and not the last element */
        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }

    va_end(args);  /* Clean up the argument list */

    printf("\n");  /* Print new line at the end */
}

