#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and initializes it with a char.
 * @size: The size of the array.
 * @c: The character to initialize the array with.
 *
 * Return: Pointer to the arrayor NULL if size is 0 or memory allocation fails.
 */

char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0) /* If size is 0, return NULL */
		return (NULL);
	arr = malloc(size * sizeof(char)); /* Allocate memory */
	if (arr == NULL) /* Check if malloc failed */
		return (NULL);
	for (i = 0; i < size; i++) /* Initialize array with char c */
		arr[i] = c;

	return (arr);
}

