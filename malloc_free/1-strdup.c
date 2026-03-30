#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string in new memory
 * @str: the string to duplicate
 *
 * Return: pointer to the new string, or NULL if it fails
 */
char *_strdup(char *str)
{
	unsigned int len = 0;
	unsigned int i = 0;
	char *copy;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	copy = malloc(len + 1);

	if (copy == NULL)
		return (NULL);

	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}

	return (copy);
}
