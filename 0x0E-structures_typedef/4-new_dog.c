#include <stdlib.h>
#include <string.h>

/**
 * new_dog - creates a new dog_t variable
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the dog's owner
 *
 * Return: a pointer to the new dog_t variable or NULL if malloc fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{

	dog_t *new_dog = malloc(sizeof(dog_t)); // Allocate memory for a new dog_t variable
    
	if (new_dog == NULL) // If malloc fails, return NULL
		return (NULL);

	new_dog->name = malloc(strlen(name) + 1); // Allocate memory for copies of name and owner
	new_dog->owner = malloc(strlen(owner) + 1);

	if (new_dog->name == NULL || new_dog->owner == NULL) { // If either malloc fails, free the memory and return NULL
	free(new_dog->name);
	free(new_dog->owner);
	free(new_dog);
	return (NULL);
    }

	strcpy(new_dog->name, name); // Copy name and owner into the new dog_t variable
	new_dog->age = age;
	strcpy(new_dog->owner, owner);

	return (new_dog); // Return a pointer to the new dog_t variable
}
