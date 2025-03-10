#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers from min to max.
 * @min: The smallest value in the array.
 * @max: The largest value in the array.
 *
 * Return: Pointer to the newly allocated array, or NULL if malloc fails
 *         or if min > max.
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	if (min > max) /* Check if min is greater than max */
		return (NULL);

	size = max - min + 1; /* Calculate size of the array */

	arr = malloc(sizeof(int) * size); /* Allocate memory */
	if (arr == NULL) /* Check if malloc failed */
		return (NULL);

	for (i = 0; i < size; i++) /* Fill array with values from min to max */
		arr[i] = min + i;

	return (arr);
}

