#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Allocates a 2D array of integers and initializes it to 0.
 * @width: The number of columns.
 * @height: The number of rows.
 *
 * Return: Pointer to the allocated 2D array, or NULL on failure.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0) /* Check for invalid dimensions */
		return (NULL);

	grid = malloc(sizeof(int *) * height); /* Allocate memory for row pointers */
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width); /* Allocate memory for each row */
		if (grid[i] == NULL) /* Check if allocation fails */
		{
			while (i >= 0) /* Free previously allocated rows */
			{
				free(grid[i]);
				i--;
			}
			free(grid);
			return (NULL);
		}

		for (j = 0; j < width; j++) /* Initialize each element to 0 */
			grid[i][j] = 0;
	}

	return (grid);
}

