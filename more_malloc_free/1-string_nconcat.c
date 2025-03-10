#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings with a limit on s2.
 * @s1: The first string.
 * @s2: The second string.
 * @n: Number of bytes from s2 to concatenate.
 *
 * Return: Pointer to the newly allocated space containing the concatenated
 *         string, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL) /* Get length of s1 */
		while (s1[len1])
			len1++;

	if (s2 != NULL) /* Get length of s2 */
		while (s2[len2])
			len2++;

	if (n >= len2) /* If n >= length of s2, use full s2 */
		n = len2;

	concat = malloc(sizeof(char) * (len1 + n + 1)); /* Allocate memory */
	if (concat == NULL) /* Check if malloc failed */
		return (NULL);

	for (i = 0; i < len1; i++) /* Copy s1 into concat */
		concat[i] = s1[i];

	for (j = 0; j < n; j++) /* Copy n bytes of s2 into concat */
		concat[i + j] = s2[j];

	concat[len1 + n] = '\0'; /* Null-terminate the concatenated string */

	return (concat);
}

