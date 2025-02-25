#include "main.h"
#include <stddef.h>

/**
 * _strcpy - Copies a string from src to dest, including '\0'.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL) /* Check for NULL pointers */
		return (NULL);

	while (src[i] != '\0') /* Copy characters until null terminator */
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0'; /* Ensure the destination is null-terminated */

	return (dest);
}

