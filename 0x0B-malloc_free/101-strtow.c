#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * count_words - counts the number of words in a string
 * @str: string to count words in
 *
 * Return: number of words in string
 */
int count_words(char *str)
{
	int count = 0, in_word = 0;

    	while (*str)
    	{
        	if (*str == ' ')
            	in_word = 0;
        	else if (!in_word)
        	{
            		in_word = 1;
            		count++;
        	}
        	str++;
    	}

    	return (count);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
    	char **words;
    	int count, i = 0;
    	char *token;

    	if (str == NULL || *str == '\0')
        	return (NULL);

    	count = count_words(str);
    	words = malloc(sizeof(char *) * (count + 1));
    	if (words == NULL)
        	return (NULL);

    	token = strtok(str, " ");
    	while (token != NULL)
    	{
        	words[i] = strdup(token);
        	if (words[i] == NULL)
        	{
            		while (i-- >= 0)
                		free(words[i]);
            			free(words);
            		return (NULL);
        	}
        	token = strtok(NULL, " ");
        	i++;
    	}
    	words[i] = NULL;

    	return (words);
}

