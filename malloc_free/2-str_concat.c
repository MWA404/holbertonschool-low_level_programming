#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: pointer to the new string, or NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	char *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	result = malloc(len1 + len2 + 1);

	if (result == NULL)
		return (NULL);

	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}

	while (j < len2)
	{
		result[i + j] = s2[j];
		j++;
	}

	result[i + j] = '\0';

	return (result);
}
