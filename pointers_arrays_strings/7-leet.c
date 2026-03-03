#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to string
 * Return: pointer to modified string
 */
char *leet(char *s)
{
	int i;
	char from[] = "aAeEoOtTlL";
	char to[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		int j;

		j = 0;
		while (from[j] != '\0')
		{
			if (s[i] == from[j])
				s[i] = to[j];
			j++;
		}
		i++;
	}
	return (s);
}
