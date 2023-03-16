#include "main.h"
#include <stdlib.hu>
/**
 * _memset - sets a block of memory with a specific value
 * @s: pointer to the block of memory to fill
 * @c: value to set
 * @n: number of bytes to fill
 *
 * Return: pointer to the block of memory
 */
char *_memset(char *s, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = c;

	return (s);
}
/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	_memset(ptr, 0, nmemb * size);

	return (ptr);
}
