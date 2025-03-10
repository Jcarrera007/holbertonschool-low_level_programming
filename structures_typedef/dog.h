#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a new structure for storing dog information.
 * @name: Pointer to a string containing the dog's name.
 * @age: The dog's age as a float.
 * @owner: Pointer to a string containing the owner's name.
 *
 * Description: This structure holds information about a dog, including
 * its name, age, and owner's name.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Typedef for struct dog */
typedef struct dog dog_t;

#endif /* DOG_H */

