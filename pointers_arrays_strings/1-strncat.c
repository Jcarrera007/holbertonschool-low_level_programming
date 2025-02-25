#include "main.h"

/**
 * _strncat - concatenates at most n characters from src to dest
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: number of bytes to concatenate
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int i = 0;

	/* find the end of dest */
	while (dest[dest_len] != '\0')
		dest_len++;

	/* Append at most n characters from src */
	while (i < n && src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}

	dest[dest_len] = '\0';

	return (dest);
}

