#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all arguments to program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0, k = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* compute length of concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* for newline character */
	}

	/* allocate memory for concatenated string */
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	/* copy arguments into concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[k++] = av[i][j];
		}
		str[k++] = '\n';
	}
	str[k] = '\0'; /* terminate string with null character */

	return (str);
}
