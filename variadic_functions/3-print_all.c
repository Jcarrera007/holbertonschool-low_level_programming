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
    void (*print_func[])(va_list) = {
        NULL, /* Placeholder for 'c' */
        NULL, /* Placeholder for 'i' */
        NULL, /* Placeholder for 'f' */
        NULL  /* Placeholder for 's' */
    };

    va_start(args, format);

    while (format && format[i])  /* First while loop */
    {
        /* Check valid format characters */
        if (format[i] == 'c' || format[i] == 'i' || format[i] == '

