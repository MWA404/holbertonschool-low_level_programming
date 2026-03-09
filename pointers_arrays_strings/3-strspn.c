#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to check
 * @accept: the accepted characters
 *
 * Return: number of bytes in s that are in accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	unsigned int j;
	int found;

	count = 0;
	while (s[count] != '\0')
	{
		found = 0;
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[count] == accept[j])
			{
				found = 1;
				break;
			}
			j++;
		}
		if (found == 0)
			return (count);
		count++;
	}
	return (count);
}
