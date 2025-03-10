#include "dog.h"
#include <stddef.h>

/**
 * init_dog - Initializes a variable of type struct dog.
 * @d: Pointer to the struct dog to initialize.
 * @name: Pointer to the dog's name.
 * @age: The dog's age.
 * @owner: Pointer to the owner's name.
 *
 * Description: If d is not NULL, assigns values to the struct dog fields.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL) /* Check if the pointer is valid */
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

