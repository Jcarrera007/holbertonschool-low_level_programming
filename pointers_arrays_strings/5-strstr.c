#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring in a string.
 * @haystack: The main string to search in.
 * @needle: The substring to find.
 *
 * Return: Pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	if (*needle == '\0') /* If needle is empty, return haystack */
		return (haystack);

	while (*haystack)
	{
		h = haystack;
		n = needle;

		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}

		if (*n == '\0') /* If end of needle is reached, substring found */
			return (haystack);

		haystack++;
	}

	return (NULL);
}

