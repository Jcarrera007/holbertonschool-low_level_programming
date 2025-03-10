#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints a struct dog.
 * @d: Pointer to the struct dog to print.
 *
 * Description: If d is NULL, the function does nothing.
 * If a field is NULL, prints (nil) instead.
 */
void print_dog(struct dog *d)
{
	if (d == NULL) /* Check if the struct pointer is NULL */
		return;

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Age: %.1f\n", d->age);
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}

