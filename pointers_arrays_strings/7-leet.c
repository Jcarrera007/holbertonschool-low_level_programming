#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: pointer to string to encode
 *
 * Return: pointer to encoded string
 */
char *leet(char *str)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++) /* loop through the input string */
	{
		for (j = 0; letters[j] != '\0'; j++) /* loop through the letters array */
		{
			if (str[i] == letters[j])
			{
				str[i] = numbers[j]; /* replace letter with corresponding digit */
				break; /* break immediately once matched */
			}
		}
	}

	return (str);
}

