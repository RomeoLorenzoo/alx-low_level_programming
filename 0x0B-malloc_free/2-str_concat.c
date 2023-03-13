#include "main.h"
#include <stdlib.h>
/**
 * str_concat - Concatenates two strings.
 * @s1: The first string to concatenate.
 * @s2: The second string to concatenate.
 *
 * Return: If concatenation fails - NULL.
 * Otherwise - a pointer to the newly-allocated space in memory
 * containing the concatenated strings, which must be freed.
 */
char *str_concat(char *s1, char *s2)
{

	char *concat;
	int len1 = 0, len2 = 0, i = 0, j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
		return (NULL);

	while (i < len1)
	{
		concat[i] = s1[i];
		i++;
	}

	while (j < len2)
	{

		concat[i] = s2[j];
		i++;
		j++;
	}

	concat[i] = '\0';

	return (concat);
}
