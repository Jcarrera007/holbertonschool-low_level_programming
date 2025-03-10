#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array and initializes it to zero.
 * @nmemb: Number of elements.
 * @size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0) /* Check for invalid inputs */
		return (NULL);

	ptr = malloc(nmemb * size); /* Allocate memory */
	if (ptr == NULL) /* Check if malloc failed */
		return (NULL);

	for (i = 0; i < (nmemb * size); i++) /* Set memory to zero */
		ptr[i] = 0;

	return ((void *)ptr);
}

