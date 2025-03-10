#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2D grid previously created by alloc_grid.
 * @grid: The 2D array to be freed.
 * @height: The number of rows in the grid.
 *
 * Return: void.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0) /* Check for NULL grid or invalid height */
		return;

	for (i = 0; i < height; i++) /* Free each row */
		free(grid[i]);

	free(grid); /* Free the main grid pointer */
}

