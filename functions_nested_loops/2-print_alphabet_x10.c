#include "main.h"  /* Ensure you have a header file with _putchar prototype */

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase 10 times
 */
void print_alphabet_x10(void)
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz\n";
    int i = 0, j;

    for (j = 0; j < 10; j++)
    {
        while (alphabet[i] != '\0')
        {
            _putchar(alphabet[i]);
            i++;
        }
        i = 0;
    }
}

