#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string in newly allocated memory.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len]) /* Get string length */
		len++;

	dup = malloc(sizeof(char) * (len + 1)); /* Allocate memory */
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++) /* Copy string */
		dup[i] = str[i];

	dup[len] = '\0'; /* Null-terminate */
	return (dup);
}

/**
 * new_dog - Creates a new dog_t instance.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the new dog_t, or NULL if allocation fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t)); /* Allocate memory for struct */
	if (dog == NULL)
		return (NULL);

	/* Duplicate name */
	dog->name = _strdup(name);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	/* Duplicate owner */
	dog->owner = _strdup(owner);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->age = age; /* Assign age */
	return (dog);
}

