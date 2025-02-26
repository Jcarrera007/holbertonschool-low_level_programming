#include "main.h"

/**
 * _strncpy - Copies a string, using at most n bytes from src.
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n) /* pad dest with null bytes if src ends early */
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

