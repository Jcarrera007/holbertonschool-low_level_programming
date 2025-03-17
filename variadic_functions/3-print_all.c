#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints anything based on the given format
 * @format: List of types of arguments passed
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str, *separator = "";

	va_start(args, format);  /* Initialize argument list */

	while (format && format[i])  /* First while loop */
	{
		if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's')
		{
			printf("%s", separator);
			separator = ", ";

			if (format[i] == 'c')
				printf("%c", va_arg(args, int));
			if (format[i] == 'i')
				printf("%d", va_arg(args, int));
			if (format[i] == 'f')
				printf("%f", va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s", str);
			}
		}
		i++;
	}

	va_end(args);  /* Clean up argument list */
	printf("\n");
}

