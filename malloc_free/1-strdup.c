#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the given string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if str is NULL
 *         or if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL) /* Check if input string is NULL */
		return (NULL);

	while (str[len]) /* Get the length of str */
		len++;

	dup = malloc(sizeof(char) * (len + 1)); /* Allocate memory */
	if (dup == NULL) /* Check if malloc failed */
		return (NULL);

	for (i = 0; i < len; i++) /* Copy the string */
		dup[i] = str[i];

	dup[len] = '\0'; /* Null-terminate the new string */
	return (dup);
}

