#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings into a newly allocated memory.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the newly allocated space containing the concatenated
 *         string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL) /* Get the length of s1 */
	{
		while (s1[len1])
			len1++;
	}

	if (s2 != NULL) /* Get the length of s2 */
	{
		while (s2[len2])
			len2++;
	}

	concat = malloc(sizeof(char) * (len1 + len2 + 1)); /* Allocate memory */
	if (concat == NULL) /* Check if malloc failed */
		return (NULL);

	for (i = 0; i < len1; i++) /* Copy s1 into concat */
		concat[i] = s1[i];

	for (j = 0; j < len2; j++) /* Copy s2 into concat */
		concat[i + j] = s2[j];

	concat[len1 + len2] = '\0'; /* Null-terminate the concatenated string */

	return (concat);
}

