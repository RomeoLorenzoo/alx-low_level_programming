#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to be evaluated.
 *
 * Return: The length of the string.
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * *_strcpy - Copies a string pointed to by src to the buffer pointed to by dest.
 * @dest: The buffer to copy the string into.
 * @src: The string to be copied.
 *
 * Return: A pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: A pointer to the new dog (Success), NULL otherwise.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len1, len2;

	len1 = _strlen(name);
	len2 = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (!dog)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len1 + 1));
	if (!dog->name)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (!dog->owner)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}

