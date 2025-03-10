#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees a dog_t structure.
 * @d: Pointer to the dog_t structure to free.
 *
 * Description: Frees memory allocated for the dog's name,
 * owner's name, and the struct itself.
 */
void free_dog(dog_t *d)
{
	if (d == NULL) /* Check if d is NULL to avoid errors */
		return;

	free(d->name);  /* Free allocated name */
	free(d->owner); /* Free allocated owner */
	free(d);        /* Free struct itself */
}

