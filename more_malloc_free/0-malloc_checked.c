#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: Number of bytes to allocate.
 *
 * Return: Pointer to the allocated memory.
 *         If malloc fails, exits with status 98.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b); /* Allocate memory */
	if (ptr == NULL) /* Check if malloc failed */
		exit(98); /* Terminate with status 98 */

	return (ptr);
}

